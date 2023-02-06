#include "GLWindowService.h"
#include <direct.h>//Ŀ¼����
#include "Logger/Src/ILogger.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "GL/glew.h"  //glew.h ���������ǰ�� ���򱨴� gl.g ����include �ڴ�֮��Ĵ���
#include "GLFW/glfw3.h"


namespace WindowsNS
{
    /// <summary>
    /// ������־�Ļص�����
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

        //���ش��ڵ�״̬
        return glfwWindowShouldClose(_pWindow);
    }

    void GLWindowService::DefaultWindowBackground()
    {
        GLCallWarn(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
        GLCallWarn(glClear(GL_COLOR_BUFFER_BIT));
    }

    int GLWindowService::StopWindows()
    {
        //ע��ֹͣ���� �������GLCallWarn 
        //�жϴ��ں󣬻�ʧȥGL�������ģ�ʧȥ������GetError �����ͻ᷵��ʧ��
        //Ȼ���ھͻ�һֱ��ѭ�������������ѭ���У����ձ���
        glfwTerminate();
        return 0;
    }

    int GLWindowService::initWinEnvir(WindowProps& pros)
    {
        //��ʼ������
        if (-1 == this->initWindows(pros))
        {
            return -1;
        }
        //��ʼ����������
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
        //���ô�����־�ص�����
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
            MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, "glewInit error");
            return -1;
        }
        //��ʼ��u��������
        return 0;
    }

    //��ʼ����������
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

    //���ش��ھ��
    GLFWwindow* GLWindowService::GetGLFWindowsHandle() const
    {
        return this->_pWindow;
    }
}