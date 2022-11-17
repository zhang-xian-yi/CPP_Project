#include "Application.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imGui/imgui.h"
#include "GLWindowService.h"
#include "FrameworkService.h"
#include "Error/ErrorMacroDefie.h"//错误检查
#include "TestRes/TestImGUIBGColor.h"
#include "TestRes/TestUIMenu.h"
#include "TestRes/TestRectangle.h"
namespace EnvirmentNS
{
    /// <summary>
    /// 构造函数
    /// </summary>
    Application::Application()
    {
        this->m_pWinS = new GLWindowService();
        this->m_pFrameTestS = new FrameworkService();
    }
    /// <summary>
    /// 析构函数
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

#pragma region 运行方法

    int Application::RunAPP()
    {
        int endFlag = 0;

        TestNS::TestBase* pCurrTest = nullptr;      
        //构造菜单
        TestResNS::TestUIMenu* pMenu = new TestResNS::TestUIMenu(pCurrTest);
        pCurrTest = pMenu;//设置

        pMenu->RegisterTest<TestResNS::TestImGUIBGColor>("TestColor");
        pMenu->RegisterTest<TestResNS::TestRectangle>("TestRectangle");
        while (!endFlag)
        {
            m_pWinS->DefaultWindowBackground();//刷新背景
            //测试样例的刷新渲染在框架上下文之间
            m_pFrameTestS->FlushFrameStart();
            //如果当前测试样例不为空
            if (pCurrTest)
            {
                pCurrTest->onUpdate(0.0f);
                pCurrTest->onRender();
                ImGui::Begin("Begin");
                //进入单独测试环境 且按钮被点击即返回true
                if (pCurrTest != pMenu && ImGui::Button("<-- 后退"))
                {
                    delete pCurrTest;
                    pCurrTest = pMenu;//恢复原
                }
                pCurrTest->onImGUIRender();
                ImGui::End();
            }
            m_pFrameTestS->FlushFrameEnd();
            endFlag = m_pWinS->FlushWindow();//刷新窗口
        }

        //TODO
        //思考使用状态机方式来确定测试用例的创建和销毁
        //先删除当前测试用例，地址值未变
        delete pCurrTest;
        //删除多余的堆
        if (pCurrTest != pMenu)
        {
            delete pMenu;
        }
        
        

        //返回就欸书标记
        return endFlag;
    }

    int Application::StopAPP()
    {
        //停止窗口
        m_pFrameTestS->EndFrameworkService();
        m_pWinS->StopWindows();
        
        return 0;
    }

#pragma endregion 运行方法

#pragma region  初始化方法
    /// <summary>
    /// 初始化环境
    /// </summary>
    /// <returns></returns>
    int Application::InitAPPEnvir(int width, int height)
    {
        InitAPPContext(width, height);

        return 0;
    }

    int Application::InitAPPContext(int width, int height)
    {
        //初始化窗口 GLF环境必须在其他业务初始哈u之前
        this->m_pWinS->initWinEnvir(width, height);

        //初始化环境
        this->m_pFrameTestS->initEnvir(this->m_pWinS->GetGLFWindowsHandle());
        return 0;
    }

#pragma endregion  初始化方法

}