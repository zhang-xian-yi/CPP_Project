#include "Application.h"
#include "ImGuiService.h"
#include "OpenGLUIService.h"
#include "../Engines/DataLoadEngine.h"
#include "../Render/RendererEngine.h"
#include "../Render/TextureService.h"
#include "../Shader/ShaderManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
/// <summary>
/// ���캯��
/// </summary>
EnvirmentNS::Application::Application()
{
    this->m_pIMGUIWinS = new EnvirmentNS::ImGuiService();
    this->m_pOpenGLWinS = new EnvirmentNS::OpenGLUIService();
}
/// <summary>
/// ��������
/// </summary>
EnvirmentNS::Application::~Application()
{
    if (m_pOpenGLWinS != nullptr)
    {
        delete m_pOpenGLWinS;
        m_pOpenGLWinS = nullptr;
    }
    if (m_pIMGUIWinS != nullptr)
    {
        delete m_pIMGUIWinS;
        m_pIMGUIWinS = nullptr;
    }
}

#pragma region ���з���

int EnvirmentNS::Application::runWindow()
{
    int endFlag = 0;
    //�������  ��endFlag Ϊ0 �Ǳ�ʾ�������������ֵΪ�쳣�����˳�
    endFlag &= m_pOpenGLWinS->runWindow();
    endFlag &= m_pIMGUIWinS->runWindow();
    //���ؾ͚G����
    return endFlag;
}

int EnvirmentNS::Application::stopWindows()
{
    m_pIMGUIWinS->stopWindows();
    m_pOpenGLWinS->stopWindows();
    return 0;
}

#pragma endregion ���з���

#pragma region  ��ʼ������
/// <summary>
/// ��ʼ������
/// </summary>
/// <returns></returns>
int EnvirmentNS::Application::InitAPPEnvir(int width,int height)
{
    initChildWindows(width,height);

    return 0;
}

int EnvirmentNS::Application::initChildWindows(int width, int height)
{
    //��ʼ������
    this->m_pOpenGLWinS->initEnvir(width, height);
    this->m_pIMGUIWinS->initEnvir(width, height);
    return 0;
}

#pragma endregion  ��ʼ������
