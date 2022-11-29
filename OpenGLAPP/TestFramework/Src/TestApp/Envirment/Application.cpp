#include "Application.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imGui/imgui.h"
#include "GLWindowService.h"
#include "FrameworkService.h"
#include "Error/ErrorMacroDefie.h"//������
#include "TestRes/TestImGUIBGColor.h"
#include "TestRes/TestUIMenu.h"
#include "TestRes/TestRectangle.h"
#include "TestRes/TestTexture2D.h"//�������
#include "TestRes/TestBatchRenderRect.h"
#include "TestRes/TestBatchRenderRect2.h"
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

        TestNS::TestBase* pCurrTest = nullptr;      
        //����˵�
        TestResNS::TestUIMenu* pMenu = new TestResNS::TestUIMenu(pCurrTest);
        pCurrTest = pMenu;//����

        pMenu->RegisterTest<TestResNS::TestImGUIBGColor>("TestColor");
        pMenu->RegisterTest<TestResNS::TestRectangle>("TestRectangle");
        pMenu->RegisterTest<TestResNS::TestTexture2D>("TestSimple2D");
        pMenu->RegisterTest<TestResNS::TestBatchRenderRect>("BatchRenderRect");
        pMenu->RegisterTest<TestResNS::TestBatchRenderRect2>("BatchRenderRect2");
        while (!endFlag)
        {
            m_pWinS->DefaultWindowBackground();//ˢ�±���
            //����������ˢ����Ⱦ�ڿ��������֮��
            m_pFrameTestS->FlushFrameStart();
            //�����ǰ����������Ϊ��
            if (pCurrTest)
            {
                pCurrTest->onUpdate(0.0f);
                pCurrTest->onRender();
                ImGui::Begin("Begin");
                //���뵥�����Ի��� �Ұ�ť�����������true
                if (pCurrTest != pMenu && ImGui::Button("<-- Back"))
                {
                    delete pCurrTest;
                    pCurrTest = pMenu;//�ָ�ԭ
                }
                pCurrTest->onImGUIRender();
                ImGui::End();
            }
            m_pFrameTestS->FlushFrameEnd();
            endFlag = m_pWinS->FlushWindow();//ˢ�´���
        }

        //TODO
        //˼��ʹ��״̬����ʽ��ȷ�����������Ĵ���������
        //��ɾ����ǰ������������ֵַδ��
        delete pCurrTest;
        //ɾ������Ķ�
        if (pCurrTest != pMenu)
        {
            delete pMenu;
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