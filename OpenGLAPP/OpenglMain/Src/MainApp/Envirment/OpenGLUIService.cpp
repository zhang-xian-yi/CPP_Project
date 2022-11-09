#include "OpenGLUIService.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <direct.h>//目录操作
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"// 投影矩阵
#include "../Engines/DataLoadEngine.h"
#include "../Shader/ShaderManager.h"
#include "../Render/RendererEngine.h"
#include "../Render/TextureService.h"
#include "../Error/ErrorMacroDefie.h"//错误处理的宏

/// <summary>
/// 构造函数
/// </summary>
EnvirmentNS::OpenGLUIService::OpenGLUIService()
{
    //没有对OpenGL 环境进行初始化之前， 不可以对gl行数进程操作
    m_pDataLoadEngine = nullptr;
    m_pShaderMag = nullptr;
    m_pRenderEngine = nullptr;
    m_pTextureService = nullptr;
}
/// <summary>
/// 析构函数
/// </summary>
EnvirmentNS::OpenGLUIService::~OpenGLUIService()
{
    EndOpenGLUIService();
}

#pragma region  初始化方法
/// <summary>
/// 初始化环境
/// </summary>
/// <returns></returns>
int EnvirmentNS::OpenGLUIService::initEnvir(GLFWwindow* glwindow)
{
    initContext();
    return 0;
}

/// <summary>
/// 初始化上下文
/// </summary>
/// <returns></returns>
int EnvirmentNS::OpenGLUIService::initContext()
{
    //初始化环境
    m_pDataLoadEngine = new EngineNS::DataLoadEngine();
    m_pShaderMag = new ShaderNS::ShaderManager();
    m_pRenderEngine = new RenderNS::RendererEngine();
    m_pTextureService = new RenderNS::TextureService();

    m_pShaderMag->initShader();
    m_pShaderMag->Bind();//必须先使用gluserprogram 才可以绑定uniform变量否则该变量不会存在

    //加载纹理
    //textureService.InitFileTexture("Resource/Textures/sky.jpeg");
    m_pTextureService->InitFileTexture("Resource/Textures/flower.jpeg");
    m_pTextureService->Bind(0);//默认为0
    m_pShaderMag->SetUniform1f("u_Texture", 0);

    //顶点数据
    float positionArray[] = {
        -100.0f,-100.0f,0.0f,0.0f,//前两个数为顶点，后两个数为纹理坐标
        100.0f,-100.0f,1.0f,0.0f,//0.0f 0.0f 纹理坐标表示左下角，1.0f,1.0f 表示右上角
        100.0f,100.0f,1.0f,1.0f,
        -100.0f,100.0f,0.0f,1.0f
    };

    //索引缓冲区
    unsigned int indices[] = {
        0,1,2,
        2,3,0,
    };

    m_pDataLoadEngine->SetVertexData(positionArray, 4 * 4 * sizeof(float));
    m_pDataLoadEngine->SetIndexData(indices, 6);
    //初始化数据环境
    m_pDataLoadEngine->InitDataEnvir();
    //正确路径
    std::cout << glGetString(GL_VERSION) << std::endl;
    return 0;
}

#pragma endregion 初始化方法

/// <summary>
/// 开始执行
/// </summary>
/// <returns></returns>
int EnvirmentNS::OpenGLUIService::FlushFrame()
{
    static float currRedValue = 0.2f;//当前的颜色
    static float redStep = 0.05f;//每次红色的步长

    /* Loop until the user closes the window */
        /* Render here */
    m_pRenderEngine->Clear();

    //建立一个投影矩阵,ortho产生一个正交矩阵
    //从左右上下来看分别时-2，2-1.5，1.5  描述从左到右时 -2 + 2 四个单位宽度
    //从上到下时 1.5+1.5 3各单位的高度的区域
    glm::mat4 projx = glm::ortho(-360.0f, 360.0f, -240.0f, 240.0f, -1.0f, 1.0f);
    //模拟视图矩阵：相机左移 意味者对象右移
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100.0f, 0.0f, 0.0f));
    //模型矩阵，xyz 三轴，x轴正向200，Y轴正向100单位，Z轴上不同
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(150, 50, 0));

    //通过反复刷新Red 值来使得正方形改变颜色
    //设置着色器统一变量 使用纹理后该变量不在着色器中使用
    m_pShaderMag->SetUniform4f("u_Color", currRedValue, 0.3f, 0.8f, 1.0f);
    //这里的0 和上面纹理插槽的0 时一个含义，描述着色器也需要统一变量赋值
    //u_Texture 为着色器的GLSL中的变量
    m_pShaderMag->SetUniformMatrix4f("u_MVP", projx * view * model);
    //绘制
    m_pRenderEngine->RendererDraw(m_pDataLoadEngine, m_pShaderMag);

    //超出边界的时候步长取反，使得颜色从0到1来回顺序变动
    
    if (currRedValue > 1.0f || currRedValue < 0.0f)
    {
        redStep = -redStep;
    }
    currRedValue += redStep;
    
    //结束
    return 0;
}

int EnvirmentNS::OpenGLUIService::EndOpenGLUIService()
{
    if (m_pDataLoadEngine != nullptr)
    {
        m_pDataLoadEngine->ReleaseSrc();
        delete m_pDataLoadEngine;
        m_pDataLoadEngine = nullptr;
    }
    //此处因为时栈区对象且为外部赋值，所以此处赋值为空
    if (m_pTextureService != nullptr)
    {
        delete m_pTextureService;
        m_pTextureService = nullptr;
    }
    if (m_pRenderEngine != nullptr)
    {
        delete m_pRenderEngine;
        m_pRenderEngine = nullptr;
    }
    if (m_pShaderMag != nullptr)
    {
        delete m_pShaderMag;
        m_pShaderMag = nullptr;
    }
    //在此之前对缓冲区进行释放
    return 0;
}
