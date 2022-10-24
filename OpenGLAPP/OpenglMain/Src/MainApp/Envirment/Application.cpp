#include "Application.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <direct.h>//目录操作
#include "../Engines/DataLoadEngine.h"
#include "../Shader/ShaderManager.h"
#include "../Render/RendererEngine.h"
#include "../Error/ErrorMacroDefie.h"//错误处理的宏
/// <summary>
/// 构造函数
/// </summary>
EnvirmentNS::Application::Application()
{
    _pWindow = nullptr;
    m_pDataLoadEngine = nullptr;
    m_pShaderMag = nullptr;
    m_pRenderEngine = nullptr;
}
/// <summary>
/// 析构函数
/// </summary>
EnvirmentNS::Application::~Application()
{
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
    if (m_pDataLoadEngine != nullptr)
    {
        delete m_pDataLoadEngine;
        m_pDataLoadEngine = nullptr;
    }
}

#pragma region  初始化方法
/// <summary>
/// 初始化环境
/// </summary>
/// <returns></returns>
int EnvirmentNS::Application::initEnvir()
{
    initWindows();
    initContext();
    initOtherConfig();
    return 0;
}

/// <summary>
/// 初始化窗口
/// </summary>
/// <returns></returns>
int EnvirmentNS::Application::initWindows()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    _pWindow = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    //初始化发生错误
    if (_pWindow == nullptr)
    {
        glfwTerminate();
        return -1;
    }
    //初始哈u窗口正常
    return 0;
}

/// <summary>
/// 初始化上下文
/// </summary>
/// <returns></returns>
int EnvirmentNS::Application::initContext()
{
    /* Make the window's context current */
    glfwMakeContextCurrent(_pWindow);

    //必须获取opengl的上下文
    if (glewInit() != GLEW_OK)
    {
        std::cout << "error" << std::endl;
        return -1;
    }
    //正确路径
    std::cout << glGetString(GL_VERSION) << std::endl;
    return 0;
}

/// <summary>
/// 初始化其他配置项目
/// </summary>
/// <returns></returns>
int EnvirmentNS::Application::initOtherConfig()
{
    //设置交换前后缓冲区的时间间隔为1，每帧刷新一次
    glfwSwapInterval(1);
    //启用透明和混合渲染
    
    //glDisable(GL_BLEND);//禁用混合
    glEnable(GL_BLEND);//启用混合
    //选择纹理中alpha数值多个alpha的插值，也就是混合
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //设置混合等式 == GL_FUNC_ADD == 设置组合源与目标值相加为组合后的新值
    glBlendEquation(GL_FUNC_ADD);
    return 0;
}
#pragma endregion 初始化方法

/// <summary>
/// 开始执行
/// </summary>
/// <returns></returns>
int EnvirmentNS::Application::runWindow()
{
    float currRedValue = 0.2f;
    float redStep = 0.05f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(_pWindow))
    {
        /* Render here */
        m_pRenderEngine->Clear();
        //通过反复刷新Red 值来使得正方形改变颜色
        //设置着色器统一变量
        m_pShaderMag->SetUniform4f("u_Color", currRedValue, 0.3f,0.8f,1.0f);
        //绘制
        m_pRenderEngine->RendererDraw(m_pDataLoadEngine,m_pShaderMag);

        //超出边界的时候步长取反，使得颜色从0到1来回顺序变动
        if (currRedValue > 1.0f || currRedValue < 0.0f)
        {
            redStep = -redStep;
        }
        currRedValue += redStep;
        /* Swap front and back buffers */
        glfwSwapBuffers(_pWindow);
        /* Poll for and process events */
        glfwPollEvents();
    }
    //结束
    return 0;
}

int EnvirmentNS::Application::stopWindows()
{
    m_pDataLoadEngine->ReleaseSrc();
    //此处因为时栈区对象且为外部赋值，所以此处赋值为空
    m_pDataLoadEngine = nullptr;
    m_pShaderMag = nullptr;
    m_pRenderEngine = nullptr;
    //在此之前对缓冲区进行释放
    GLCallWarn(glfwTerminate());
    return 0;
}

/// <summary>
/// 设置数据引擎
/// </summary>
/// <param name="pEngine"></param>
void EnvirmentNS::Application::SetEngineRes(EngineNS::DataLoadEngine* pDLEngine, ShaderNS::ShaderManager* pShader, RenderNS::RendererEngine* pRender)
{
    this->m_pDataLoadEngine = pDLEngine;
    this->m_pRenderEngine = pRender;
    this->m_pShaderMag = pShader;
}
