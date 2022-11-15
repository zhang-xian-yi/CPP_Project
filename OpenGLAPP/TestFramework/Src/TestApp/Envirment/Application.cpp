#include "Application.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GLWindowService.h"
#include "FrameworkService.h"
#include "Error/ErrorMacroDefie.h"//������
#include "TestRes/TestImGUIBGColor.h"
namespace EnvirmentNS
{
    /// <summary>
    /// ���캯��
    /// </summary>
    Application::Application()
    {
        this->m_pWinS = new GLWindowService();
        this->m_pFrameTestS = new FrameworkService();
    }
    /// <summary>
    /// ��������
    /// </summary>
    Application::~Application()
    {
        if (m_pFrameTestS != nullptr)
        {
            delete m_pFrameTestS;
            m_pFrameTestS = nullptr;
        }

        if (m_pWinS != nullptr)
        {
            delete m_pWinS;
            m_pWinS = nullptr;
        }
    }

#pragma region ���з���

    int Application::RunAPP()
    {
        int endFlag = 0;

        TestResNS::TestImGUIBGColor colorTest;

        while (!endFlag)
        {
            //�������  ��endFlag Ϊ0 �Ǳ�ʾ�������������ֵΪ�쳣�����˳�                
            colorTest.onUpdate(0.0f);
            colorTest.onRender();

            //����������ˢ����Ⱦ�ڿ��������֮��
            m_pFrameTestS->FlushFrameStart();
            colorTest.onImGUIRender();
            m_pFrameTestS->FlushFrameEnd();

            endFlag = m_pWinS->FlushWindow();//ˢ�´���
        }

        //���ؾ͚G����
        return endFlag;
    }

    int Application::StopAPP()
    {
        //ֹͣ����
        m_pFrameTestS->EndFrameworkService();
        m_pWinS->StopWindows();
        
        return 0;
    }

#pragma endregion ���з���

#pragma region  ��ʼ������
    /// <summary>
    /// ��ʼ������
    /// </summary>
    /// <returns></returns>
    int Application::InitAPPEnvir(int width, int height)
    {
        InitAPPContext(width, height);

        return 0;
    }

    int Application::InitAPPContext(int width, int height)
    {
        //��ʼ������ GLF��������������ҵ���ʼ��u֮ǰ
        this->m_pWinS->initWinEnvir(width, height);

        //��ʼ������
        this->m_pFrameTestS->initEnvir(this->m_pWinS->GetGLFWindowsHandle());
        return 0;
    }

#pragma endregion  ��ʼ������

}