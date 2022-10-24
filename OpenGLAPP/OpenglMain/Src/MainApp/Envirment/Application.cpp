#include "Application.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <direct.h>//Ŀ¼����
#include "../Engines/DataLoadEngine.h"
#include "../Shader/ShaderManager.h"
#include "../Render/RendererEngine.h"
#include "../Error/ErrorMacroDefie.h"//������ĺ�
/// <summary>
/// ���캯��
/// </summary>
EnvirmentNS::Application::Application()
{
    _pWindow = nullptr;
    m_pDataLoadEngine = nullptr;
    m_pShaderMag = nullptr;
    m_pRenderEngine = nullptr;
}
/// <summary>
/// ��������
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

#pragma region  ��ʼ������
/// <summary>
/// ��ʼ������
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
/// ��ʼ������
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
    //��ʼ����������
    if (_pWindow == nullptr)
    {
        glfwTerminate();
        return -1;
    }
    //��ʼ��u��������
    return 0;
}

/// <summary>
/// ��ʼ��������
/// </summary>
/// <returns></returns>
int EnvirmentNS::Application::initContext()
{
    /* Make the window's context current */
    glfwMakeContextCurrent(_pWindow);

    //�����ȡopengl��������
    if (glewInit() != GLEW_OK)
    {
        std::cout << "error" << std::endl;
        return -1;
    }
    //��ȷ·��
    std::cout << glGetString(GL_VERSION) << std::endl;
    return 0;
}

/// <summary>
/// ��ʼ������������Ŀ
/// </summary>
/// <returns></returns>
int EnvirmentNS::Application::initOtherConfig()
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
int EnvirmentNS::Application::runWindow()
{
    float currRedValue = 0.2f;
    float redStep = 0.05f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(_pWindow))
    {
        /* Render here */
        m_pRenderEngine->Clear();
        //ͨ������ˢ��Red ֵ��ʹ�������θı���ɫ
        //������ɫ��ͳһ����
        m_pShaderMag->SetUniform4f("u_Color", currRedValue, 0.3f,0.8f,1.0f);
        //����
        m_pRenderEngine->RendererDraw(m_pDataLoadEngine,m_pShaderMag);

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
    }
    //����
    return 0;
}

int EnvirmentNS::Application::stopWindows()
{
    m_pDataLoadEngine->ReleaseSrc();
    //�˴���Ϊʱջ��������Ϊ�ⲿ��ֵ�����Դ˴���ֵΪ��
    m_pDataLoadEngine = nullptr;
    m_pShaderMag = nullptr;
    m_pRenderEngine = nullptr;
    //�ڴ�֮ǰ�Ի����������ͷ�
    GLCallWarn(glfwTerminate());
    return 0;
}

/// <summary>
/// ������������
/// </summary>
/// <param name="pEngine"></param>
void EnvirmentNS::Application::SetEngineRes(EngineNS::DataLoadEngine* pDLEngine, ShaderNS::ShaderManager* pShader, RenderNS::RendererEngine* pRender)
{
    this->m_pDataLoadEngine = pDLEngine;
    this->m_pRenderEngine = pRender;
    this->m_pShaderMag = pShader;
}
