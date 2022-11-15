#include "Application.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GLWindowService.h"
#include "FrameworkService.h"
#include "Error/ErrorMacroDefie.h"//错误检查
#include "TestRes/TestImGUIBGColor.h"
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

        TestResNS::TestImGUIBGColor colorTest;

        while (!endFlag)
        {
            //结束标记  但endFlag 为0 是表示正常情况，其他值为异常或则退出                
            colorTest.onUpdate(0.0f);
            colorTest.onRender();

            //测试样例的刷新渲染在框架上下文之间
            m_pFrameTestS->FlushFrameStart();
            colorTest.onImGUIRender();
            m_pFrameTestS->FlushFrameEnd();

            endFlag = m_pWinS->FlushWindow();//刷新窗口
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