#include "GLWindowService.h"
#include <iostream>
#include <direct.h>//目录操作
#include "Error/ErrorMacroDefie.h"//错误检查
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace EnvirmentNS
{
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
        glfwSwapBuffers(_pWindow);
        /* Poll for and process events */
        // Poll and handle events (inputs, window resize, etc.) 
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        //返回窗口的状态
        return glfwWindowShouldClose(_pWindow);
    }

    int GLWindowService::StopWindows()
    {
        glfwTerminate();
        return 0;
    }

    int GLWindowService::initWinEnvir(int width, int height)
    {
        //初始化窗口
        this->initWindows(width, height);
        //初始化窗口配置
        this->initWindowsConfig();
        return 0;
    }

    int GLWindowService::initWindows(int width, int height)
    {
        /* Initialize the library */
        if (!glfwInit())
        {
            return -1;
        }

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
        _pWindow = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
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
            std::cout << "error" << std::endl;
            return -1;
        }
        //初始哈u窗口正常
        return 0;
    }

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

    GLFWwindow* GLWindowService::GetGLFWindowsHandle() const
    {
        return this->_pWindow;
    }
}