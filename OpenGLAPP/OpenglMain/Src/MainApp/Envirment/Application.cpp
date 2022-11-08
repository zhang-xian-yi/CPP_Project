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
/// 构造函数
/// </summary>
EnvirmentNS::Application::Application()
{
    this->m_pIMGUIWinS = new EnvirmentNS::ImGuiService();
    this->m_pOpenGLWinS = new EnvirmentNS::OpenGLUIService();
}
/// <summary>
/// 析构函数
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

#pragma region 运行方法

int EnvirmentNS::Application::runWindow()
{
    int endFlag = 0;
    //结束标记  但endFlag 为0 是表示正常情况，其他值为异常或则退出
    endFlag &= m_pOpenGLWinS->runWindow();
    endFlag &= m_pIMGUIWinS->runWindow();
    //返回就欸书标记
    return endFlag;
}

int EnvirmentNS::Application::stopWindows()
{
    m_pIMGUIWinS->stopWindows();
    m_pOpenGLWinS->stopWindows();
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
    initChildWindows(width,height);

    return 0;
}

int EnvirmentNS::Application::initChildWindows(int width, int height)
{
    //初始化环境
    this->m_pOpenGLWinS->initEnvir(width, height);
    this->m_pIMGUIWinS->initEnvir(width, height);
    return 0;
}

#pragma endregion  初始化方法
