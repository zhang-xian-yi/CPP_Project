#include "FrameworkService.h"
#include "imGui/imgui.h"
#include "imGui/imgui_impl_glfw.h"
#include "imGui/imgui_impl_opengl3.h"
#include "Error/ErrorMacroDefie.h"
#include "GLFW/glfw3.h"
#include "GL/glew.h"
namespace EnvirmentNS
{
	FrameworkService::FrameworkService()
	{
	}

	FrameworkService::~FrameworkService()
	{
	}

	int FrameworkService::initEnvir(GLFWwindow* window)
	{
		m_pWindow = window;
		initImGUI();//初始化IMGUI
		return 0;
	}

	int FrameworkService::FlushFrameStart()
	{
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		return 0;
	}

	int FrameworkService::FlushFrameEnd()
	{
		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		return 0;
	}

	//停止框架的业务
	int FrameworkService::EndFrameworkService()
	{
		// Cleanup
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		glfwDestroyWindow(this->m_pWindow);
		return 0;
	}

	//初始化IMGUI
	int FrameworkService::initImGUI()
	{
		const char* glsl_version = "#version 130";

		glfwMakeContextCurrent(m_pWindow);
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
		ImGui_ImplGlfw_InitForOpenGL(m_pWindow, true);
		ImGui_ImplOpenGL3_Init(glsl_version);

		return 0;
	}
}