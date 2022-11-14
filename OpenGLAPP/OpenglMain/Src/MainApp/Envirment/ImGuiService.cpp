#include "ImGuiService.h"
#include <stdio.h>

#include "imGui/imgui.h"
#include "imGui/imgui_impl_glfw.h"
#include "imGui/imgui_impl_opengl3.h"
#include "Entity/RenderMatrixObj.h"//渲染对象处理
#include "Error/ErrorMacroDefie.h"//错误检查
#include <GL/glew.h>
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif


// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

EnvirmentNS::ImGuiService::ImGuiService()
{
}

EnvirmentNS::ImGuiService::~ImGuiService()
{
}

int EnvirmentNS::ImGuiService::initEnvir(GLFWwindow* window)
{
    m_pWindow = window;//保存指针

    initContext(window);
	return 0;
}

int EnvirmentNS::ImGuiService::FlushFrame(EntityNS::RenderObj& renderObj)
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
    {
        //ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
        //将模型矩阵的x坐标 与滑动Slider 绑定起来 注意这里的3
        //描述三个滑动条分别控制XYZ三个值
        ImGui::SliderFloat3("ModelA", &(renderObj.GetModelAMatrix()->x), 0.0f, 720.0f);
        ImGui::Text("--------------------------------------------------------");
        ImGui::SliderFloat3("ModelB", &(renderObj.GetModelBMatrix()->x), 0.0f, 720.0f);
        //ImGui::End();
    }
    // Rendering
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    //结束
    return 0;
}

int EnvirmentNS::ImGuiService::EndIMGUIService()
{
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(this->m_pWindow);
	return 0;
}

int EnvirmentNS::ImGuiService::initContext(GLFWwindow* window)
{
    const char* glsl_version = "#version 130";

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    return 0;
}
