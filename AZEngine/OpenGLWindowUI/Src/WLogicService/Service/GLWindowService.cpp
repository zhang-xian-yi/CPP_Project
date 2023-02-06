#include "GLWindowService.h"
#include <direct.h>//目录操作
#include "Logger/Src/ILogger.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "GL/glew.h"  //glew.h 必须放在最前面 否则报错 gl.g 必须include 在此之后的错误
#include "GLFW/glfw3.h"


namespace WindowsNS
{
    /// <summary>
    /// 错误日志的回调函数
    /// </summary>
    /// <param name="error"></param>
    /// <param name="description"></param>
    static void GLFWErrorCallback(int error, const char* description)
    {
        MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, "GLFW Error :", std::to_string(error), "  ", std::string(description));
    }

    GLWindowService::GLWindowService()
        :_pWindow(nullptr)
    {
    }

    GLWindowService::~GLWindowService()
    {

    }

    int GLWindowService::FlushWindow()
    {
        /* Swap front and back buffers */
        GLCallWarn(glfwSwapBuffers(_pWindow));
        /* Poll for and process events */
        // Poll and handle events (inputs, window resize, etc.) 
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        GLCallWarn(glfwPollEvents());

        //返回窗口的状态
        return glfwWindowShouldClose(_pWindow);
    }

    void GLWindowService::DefaultWindowBackground()
    {
        GLCallWarn(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
        GLCallWarn(glClear(GL_COLOR_BUFFER_BIT));
    }

    int GLWindowService::StopWindows()
    {
        //注意停止窗口 不能添加GLCallWarn 
        //中断窗口后，会失去GL的上下文，失去上下文GetError 方法就会返回失败
        //然后在就会一直死循环在消除错误的循环中，最终报错
        glfwTerminate();
        return 0;
    }

    int GLWindowService::initWinEnvir(WindowProps& pros)
    {
        //初始化窗口
        if (-1 == this->initWindows(pros))
        {
            return -1;
        }
        //初始化窗口配置
        this->initWindowsConfig();
        return 0;
    }

    int GLWindowService::initWindows(WindowProps& pros)
    {
        /* Initialize the library */
        if (!glfwInit())
        {
            return -1;
        }
        //设置错误日志回调函数
        glfwSetErrorCallback(GLFWErrorCallback);

        // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
        const char* glsl_version = "#version 100";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
        const char* glsl_version = "#version 150";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
        // GL 3.0 + GLSL 130
        const char* glsl_version = "#version 130";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

        /* Create a windowed mode window and its OpenGL context */
        _pWindow = glfwCreateWindow(pros.Width, pros.Height, pros.Title.c_str(), NULL, NULL);
        //初始化发生错误
        if (_pWindow == nullptr)
        {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(_pWindow);

        //必须获取opengl的上下文
        if (glewInit() != GLEW_OK)
        {
            MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, "glewInit error");
            return -1;
        }
        //初始哈u窗口正常
        return 0;
    }

    //初始化窗口配置
    int GLWindowService::initWindowsConfig()
    {
        //设置交换前后缓冲区的时间间隔为1，每帧刷新一次
        glfwSwapInterval(2);
        //启用透明和混合渲染    
        //glDisable(GL_BLEND);//禁用混合
        glEnable(GL_BLEND);//启用混合
        //选择纹理中alpha数值多个alpha的插值，也就是混合
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //设置混合等式 == GL_FUNC_ADD == 设置组合源与目标值相加为组合后的新值
        glBlendEquation(GL_FUNC_ADD);
        return 0;
    }

    //返回窗口句柄
    GLFWwindow* GLWindowService::GetGLFWindowsHandle() const
    {
        return this->_pWindow;
    }
}