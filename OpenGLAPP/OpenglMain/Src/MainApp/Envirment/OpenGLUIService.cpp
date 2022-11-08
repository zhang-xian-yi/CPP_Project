#include "OpenGLUIService.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <direct.h>//Ŀ¼����
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"// ͶӰ����
#include "../Engines/DataLoadEngine.h"
#include "../Shader/ShaderManager.h"
#include "../Render/RendererEngine.h"
#include "../Render/TextureService.h"
#include "../Error/ErrorMacroDefie.h"//������ĺ�

/// <summary>
/// ���캯��
/// </summary>
EnvirmentNS::OpenGLUIService::OpenGLUIService()
{
    _pWindow = nullptr;
    //û�ж�OpenGL �������г�ʼ��֮ǰ�� �����Զ�gl�������̲���
    m_pDataLoadEngine = nullptr;
    m_pShaderMag = nullptr;
    m_pRenderEngine = nullptr;
    m_pTextureService = nullptr;
}
/// <summary>
/// ��������
/// </summary>
EnvirmentNS::OpenGLUIService::~OpenGLUIService()
{
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
    if (m_pDataLoadEngine != nullptr)
    {
        delete m_pDataLoadEngine;
        m_pDataLoadEngine = nullptr;
    }
}

#pragma region  ��ʼ������
/// <summary>
/// ��ʼ������
/// </summary>
/// <returns></returns>
int EnvirmentNS::OpenGLUIService::initEnvir(int width, int height)
{
    initWindows(width, height);
    initContext();
    initOtherConfig();
    return 0;
}

/// <summary>
/// ��ʼ������
/// </summary>
/// <returns></returns>
int EnvirmentNS::OpenGLUIService::initWindows(int width, int height)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        return -1;
    }

    // GL 3.0 + GLSL 130
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    /* Create a windowed mode window and its OpenGL context */
    _pWindow = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    //��ʼ����������
    if (_pWindow == nullptr)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(_pWindow);

    //�����ȡopengl��������
    if (glewInit() != GLEW_OK)
    {
        std::cout << "error" << std::endl;
        return -1;
    }
    //��ʼ��u��������
    return 0;
}

/// <summary>
/// ��ʼ��������
/// </summary>
/// <returns></returns>
int EnvirmentNS::OpenGLUIService::initContext()
{
    //��ʼ������
    m_pDataLoadEngine = new EngineNS::DataLoadEngine();
    m_pShaderMag = new ShaderNS::ShaderManager();
    m_pRenderEngine = new RenderNS::RendererEngine();
    m_pTextureService = new RenderNS::TextureService();

    m_pShaderMag->initShader();
    m_pShaderMag->Bind();//������ʹ��gluserprogram �ſ��԰�uniform��������ñ����������

    //��������
    //textureService.InitFileTexture("Resource/Textures/sky.jpeg");
    m_pTextureService->InitFileTexture("Resource/Textures/flower.jpeg");
    m_pTextureService->Bind(0);//Ĭ��Ϊ0
    m_pShaderMag->SetUniform1f("u_Texture", 0);

    //��������
    float positionArray[] = {
        -100.0f,-100.0f,0.0f,0.0f,//ǰ������Ϊ���㣬��������Ϊ��������
        100.0f,-100.0f,1.0f,0.0f,//0.0f 0.0f ���������ʾ���½ǣ�1.0f,1.0f ��ʾ���Ͻ�
        100.0f,100.0f,1.0f,1.0f,
        -100.0f,100.0f,0.0f,1.0f
    };

    //����������
    unsigned int indices[] = {
        0,1,2,
        2,3,0,
    };

    m_pDataLoadEngine->SetVertexData(positionArray, 4 * 4 * sizeof(float));
    m_pDataLoadEngine->SetIndexData(indices, 6);
    //��ʼ�����ݻ���
    m_pDataLoadEngine->InitDataEnvir();
    //��ȷ·��
    std::cout << glGetString(GL_VERSION) << std::endl;
    return 0;
}

/// <summary>
/// ��ʼ������������Ŀ
/// </summary>
/// <returns></returns>
int EnvirmentNS::OpenGLUIService::initOtherConfig()
{
    //���ý���ǰ�󻺳�����ʱ����Ϊ1��ÿ֡ˢ��һ��
    glfwSwapInterval(1);
    //����͸���ͻ����Ⱦ    
    //glDisable(GL_BLEND);//���û��
    glEnable(GL_BLEND);//���û��
    //ѡ��������alpha��ֵ���alpha�Ĳ�ֵ��Ҳ���ǻ��
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //���û�ϵ�ʽ == GL_FUNC_ADD == �������Դ��Ŀ��ֵ���Ϊ��Ϻ����ֵ
    glBlendEquation(GL_FUNC_ADD);
    return 0;
}
#pragma endregion ��ʼ������

/// <summary>
/// ��ʼִ��
/// </summary>
/// <returns></returns>
int EnvirmentNS::OpenGLUIService::runWindow()
{
    float currRedValue = 0.2f;
    float redStep = 0.05f;
    /* Loop until the user closes the window */
        /* Render here */
    m_pRenderEngine->Clear();

    //����һ��ͶӰ����,ortho����һ����������
    //���������������ֱ�ʱ-2��2-1.5��1.5  ����������ʱ -2 + 2 �ĸ���λ���
    //���ϵ���ʱ 1.5+1.5 3����λ�ĸ߶ȵ�����
    glm::mat4 projx = glm::ortho(-360.0f, 360.0f, -240.0f, 240.0f, -1.0f, 1.0f);
    //ģ����ͼ����������� ��ζ�߶�������
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100.0f, 0.0f, 0.0f));
    //ģ�;���xyz ���ᣬx������200��Y������100��λ��Z���ϲ�ͬ
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(150, 50, 0));

    //ͨ������ˢ��Red ֵ��ʹ�������θı���ɫ
    //������ɫ��ͳһ���� ʹ�������ñ���������ɫ����ʹ��
    m_pShaderMag->SetUniform4f("u_Color", currRedValue, 0.3f, 0.8f, 1.0f);
    //�����0 �����������۵�0 ʱһ�����壬������ɫ��Ҳ��Ҫͳһ������ֵ
    //u_Texture Ϊ��ɫ����GLSL�еı���
    m_pShaderMag->SetUniformMatrix4f("u_MVP", projx * view * model);
    //����
    m_pRenderEngine->RendererDraw(m_pDataLoadEngine, m_pShaderMag);

    //�����߽��ʱ�򲽳�ȡ����ʹ����ɫ��0��1����˳��䶯
    if (currRedValue > 1.0f || currRedValue < 0.0f)
    {
        redStep = -redStep;
    }
    currRedValue += redStep;
    /* Swap front and back buffers */
    glfwSwapBuffers(_pWindow);
    /* Poll for and process events */
    glfwPollEvents();
    //����
    return glfwWindowShouldClose(_pWindow);
}

int EnvirmentNS::OpenGLUIService::stopWindows()
{
    m_pDataLoadEngine->ReleaseSrc();
    //�˴���Ϊʱջ��������Ϊ�ⲿ��ֵ�����Դ˴���ֵΪ��
    m_pDataLoadEngine = nullptr;
    m_pShaderMag = nullptr;
    m_pRenderEngine = nullptr;
    //�ڴ�֮ǰ�Ի����������ͷ�
    glfwTerminate();
    return 0;
}