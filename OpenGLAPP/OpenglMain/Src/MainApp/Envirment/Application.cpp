#include "Application.h"
#include "ImGuiService.h"
#include "OpenGLUIService.h"
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
    while (!endFlag)
    {
        //���¸�ֵ
        endFlag &= m_pIMGUIWinS->runWindow();
        endFlag &= m_pOpenGLWinS->runWindow();
    }
    //����ѭ�� ��ʾAPP����
    endFlag = 0;
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
int EnvirmentNS::Application::initEnvir(int width,int height)
{
    initWindows(width,height);
    initContext();
    initOtherConfig();
    return 0;
}

int EnvirmentNS::Application::initWindows(int width, int height)
{
    return 0;
}

int EnvirmentNS::Application::initContext()
{
    return 0;
}

int EnvirmentNS::Application::initOtherConfig()
{
    return 0;
}

#pragma endregion  ��ʼ������
