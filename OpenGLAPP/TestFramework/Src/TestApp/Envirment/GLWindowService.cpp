#include "GLWindowService.h"
#include <iostream>
#include <direct.h>//Ŀ¼����
#include "Error/ErrorMacroDefie.h"//������
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

        //���ش��ڵ�״̬
        return glfwWindowShouldClose(_pWindow);
    }

    int GLWindowService::StopWindows()
    {
        glfwTerminate();
        return 0;
    }

    int GLWindowService::initWinEnvir(int width, int height)
    {
        //��ʼ������
        this->initWindows(width, height);
        //��ʼ����������
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
        //��ʼ����������
        if (_pWindow == nullptr)
        {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(_pWindow);

        //�����ȡopengl��������
        if (glewInit() != GLEW_OK)
        {
            std::cout << "error" << std::endl;
            return -1;
        }
        //��ʼ��u��������
        return 0;
    }

    int GLWindowService::initWindowsConfig()
    {
        //���ý���ǰ�󻺳�����ʱ����Ϊ1��ÿ֡ˢ��һ��
        glfwSwapInterval(2);
        //����͸���ͻ����Ⱦ    
        //glDisable(GL_BLEND);//���û��
        glEnable(GL_BLEND);//���û��
        //ѡ��������alpha��ֵ���alpha�Ĳ�ֵ��Ҳ���ǻ��
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //���û�ϵ�ʽ == GL_FUNC_ADD == �������Դ��Ŀ��ֵ���Ϊ��Ϻ����ֵ
        glBlendEquation(GL_FUNC_ADD);
        return 0;
    }

    GLFWwindow* GLWindowService::GetGLFWindowsHandle() const
    {
        return this->_pWindow;
    }
}