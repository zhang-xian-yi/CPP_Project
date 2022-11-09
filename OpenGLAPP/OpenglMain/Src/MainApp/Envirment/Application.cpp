#include "Application.h"
#include "ImGuiService.h"
#include "OpenGLUIService.h"
#include "GLWindowService.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
/// <summary>
/// ���캯��
/// </summary>
EnvirmentNS::Application::Application()
{
    this->m_pWinS = new EnvirmentNS::GLWindowService();
    this->m_pIMGUIS = new EnvirmentNS::ImGuiService();
    this->m_pOpenGLUIS = new EnvirmentNS::OpenGLUIService();
}
/// <summary>
/// ��������
/// </summary>
EnvirmentNS::Application::~Application()
{
    if (m_pOpenGLUIS != nullptr)
    {
        delete m_pOpenGLUIS;
        m_pOpenGLUIS = nullptr;
    }
    if (m_pIMGUIS != nullptr)
    {
        delete m_pIMGUIS;
        m_pIMGUIS = nullptr;
    }
    if (m_pWinS != nullptr)
    {
        delete m_pWinS;
        m_pWinS = nullptr;
    }
}

#pragma region ���з���

int EnvirmentNS::Application::RunAPP()
{
    int endFlag = 0;

    while (!endFlag)
    {
        //�������  ��endFlag Ϊ0 �Ǳ�ʾ�������������ֵΪ�쳣�����˳�
        m_pOpenGLUIS->FlushFrame();
        m_pIMGUIS->FlushFrame();
        endFlag = m_pWinS->FlushWindow();//ˢ�´���
    }

    //���ؾ͚G����
    return endFlag;
}

int EnvirmentNS::Application::StopAPP()
{
    m_pIMGUIS->EndIMGUIService();
    m_pOpenGLUIS->EndOpenGLUIService();
    //ֹͣ����
    m_pWinS->StopWindows();
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
    InitAPPContext(width,height);

    return 0;
}

int EnvirmentNS::Application::InitAPPContext(int width, int height)
{
    //��ʼ������ GLF��������������ҵ���ʼ��u֮ǰ
    this->m_pWinS->initWinEnvir(width, height);

    //��ʼ������
    this->m_pOpenGLUIS->initEnvir(this->m_pWinS->GetGLFWindowsHandle());
    this->m_pIMGUIS->initEnvir(this->m_pWinS->GetGLFWindowsHandle());
    return 0;
}

#pragma endregion  ��ʼ������
