#include "Application.h"
#include "ImGuiService.h"
#include "OpenGLUIService.h"
#include "GLWindowService.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
/// <summary>
/// 构造函数
/// </summary>
EnvirmentNS::Application::Application()
{
    this->m_pWinS = new EnvirmentNS::GLWindowService();
    this->m_pIMGUIS = new EnvirmentNS::ImGuiService();
    this->m_pOpenGLUIS = new EnvirmentNS::OpenGLUIService();
}
/// <summary>
/// 析构函数
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

#pragma region 运行方法

int EnvirmentNS::Application::RunAPP()
{
    int endFlag = 0;

    while (!endFlag)
    {
        //结束标记  但endFlag 为0 是表示正常情况，其他值为异常或则退出
        m_pOpenGLUIS->FlushFrame();
        m_pIMGUIS->FlushFrame();
        endFlag = m_pWinS->FlushWindow();//刷新窗口
    }

    //返回就欸书标记
    return endFlag;
}

int EnvirmentNS::Application::StopAPP()
{
    m_pIMGUIS->EndIMGUIService();
    m_pOpenGLUIS->EndOpenGLUIService();
    //停止窗口
    m_pWinS->StopWindows();
    return 0;
}

#pragma endregion 运行方法

#pragma region  初始化方法
/// <summary>
/// 初始化环境
/// </summary>
/// <returns></returns>
int EnvirmentNS::Application::InitAPPEnvir(int width,int height)
{
    InitAPPContext(width,height);

    return 0;
}

int EnvirmentNS::Application::InitAPPContext(int width, int height)
{
    //初始化窗口 GLF环境必须在其他业务初始哈u之前
    this->m_pWinS->initWinEnvir(width, height);

    //初始化环境
    this->m_pOpenGLUIS->initEnvir(this->m_pWinS->GetGLFWindowsHandle());
    this->m_pIMGUIS->initEnvir(this->m_pWinS->GetGLFWindowsHandle());
    return 0;
}

#pragma endregion  初始化方法
