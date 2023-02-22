#include "ImGuiLayer.h"
#include "Imgui/imgui.h"
#include "Imgui/imgui_internal.h"
#include "Imgui/imconfig.h"
#include "Imgui/imstb_rectpack.h"
#include "Imgui/imstb_textedit.h"
#include "Imgui/imstb_truetype.h"
#include "Imgui/imgui_impl_glfw.h"
#include "Imgui/imgui_impl_opengl3.h"

#include "MdlCommon/Src/CMNServices/Utils/PathUtil.h"//Â·¾¶
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//·þÎñÈÝÆ÷
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "OpenGLWindowUI/Src/IWindow.h"
#include "LayerCommon/Src/SysEvents/ISysEvent.h"
// TEMPORARY

#include "glad/glad.h"
#include "GLFW/glfw3.h"

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

namespace ImguiRendererNS {

	ImGuiLayer::ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		auto pWinS = MdlCommonNS::ServiceContainerSingle::GetInstance().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_OpenGLWindow_Type);
		WindowsNS::IWindow* pwin = pWinS.value()->ConvertType<WindowsNS::IWindow*>();
		GLFWwindow* window = (GLFWwindow*)((pwin)->GetNativeWindow());
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

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 130");//not init openGL loader! error
	}

	void ImGuiLayer::OnDetach()
	{
		// Cleanup
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	bool ImGuiLayer::OnEvent(LayerCommonNS::ISysEvent& e)
	{
		if (m_BlockEvents)
		{
			ImGuiIO& io = ImGui::GetIO();
			e.IsHandle |= e.IsInCategory(LayerCommonNS::ESysEventCategory::EventCategoryMouse) & io.WantCaptureMouse;
			e.IsHandle |= e.IsInCategory(LayerCommonNS::ESysEventCategory::EventCategoryKeyboard) & io.WantCaptureKeyboard;
		}
		return e.IsHandle;
	}

	void ImGuiLayer::OnRender()
	{
		Begin();
		ImGui::Begin("NewFrame");
		ImGui::Button("NewFrame");
		ImGui::Text("----------------------------------------XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		ImGui::End();
		End();
	}

	void ImGuiLayer::OnUpdate()
	{
		
	}
	
	void ImGuiLayer::Begin()
	{
		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::End()
	{
		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::SetDarkThemeColors()
	{
		auto& colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f, 0.105f, 0.11f, 1.0f };

		// Headers
		colors[ImGuiCol_Header] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
		colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
		colors[ImGuiCol_HeaderActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		
		// Buttons
		colors[ImGuiCol_Button] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
		colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
		colors[ImGuiCol_ButtonActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

		// Frame BG
		colors[ImGuiCol_FrameBg] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
		colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
		colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

		// Tabs
		colors[ImGuiCol_Tab] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		colors[ImGuiCol_TabHovered] = ImVec4{ 0.38f, 0.3805f, 0.381f, 1.0f };
		colors[ImGuiCol_TabActive] = ImVec4{ 0.28f, 0.2805f, 0.281f, 1.0f };
		colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };

		// Title
		colors[ImGuiCol_TitleBg] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
	}

}
