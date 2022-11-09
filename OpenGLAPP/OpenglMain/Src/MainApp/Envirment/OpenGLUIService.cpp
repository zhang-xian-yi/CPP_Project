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
    EndOpenGLUIService();
}

#pragma region  ��ʼ������
/// <summary>
/// ��ʼ������
/// </summary>
/// <returns></returns>
int EnvirmentNS::OpenGLUIService::initEnvir(GLFWwindow* glwindow)
{
    initContext();
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

#pragma endregion ��ʼ������

/// <summary>
/// ��ʼִ��
/// </summary>
/// <returns></returns>
int EnvirmentNS::OpenGLUIService::FlushFrame()
{
    static float currRedValue = 0.2f;//��ǰ����ɫ
    static float redStep = 0.05f;//ÿ�κ�ɫ�Ĳ���

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
    
    //����
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
    //�˴���Ϊʱջ��������Ϊ�ⲿ��ֵ�����Դ˴���ֵΪ��
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
    //�ڴ�֮ǰ�Ի����������ͷ�
    return 0;
}
