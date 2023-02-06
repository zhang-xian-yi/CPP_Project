#include "OpenGLWindows.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"//模块类型
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"
#include "MdlCommon/Src/CMNMacro/TypeMacroDef.h"
#include "OpenGLWindowUI/Src/IWindow.h"
#include "Logger/Src/ILogger.h"
#include "EventCommon/Src/SysEvents.h"//系统事件
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace WindowsNS
{
	static uint8_t s_GLFWWindowCount = 0;

	OpenGLWindows::OpenGLWindows(const WindowProps& props)
		:m_WinService(new GLWindowService())
	{
		m_Data.WinPros = props;
	}

	OpenGLWindows::~OpenGLWindows()
	{
		Shutdown();
	}

	void OpenGLWindows::Show()
	{
		MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV, "Creating window ", m_Data.WinPros.Title, ", ", std::to_string(m_Data.WinPros.Width), ", ", std::to_string(m_Data.WinPros.Height));

		
		if (s_GLFWWindowCount == 0)
		{
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV,"glfwInit");
			auto success = m_WinService->initWinEnvir(m_Data.WinPros);
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV," initialize GLFW :", std::to_string(success) );
			
		}
		auto GLWin = m_WinService->GetGLFWindowsHandle();

		glfwSetWindowUserPointer(GLWin, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(GLWin, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.WinPros.Width = width;
				data.WinPros.Height = height;

				EventCommonNS::WindowResizeEvent eve(width, height);
				data.EventCallback(eve);
			});

		glfwSetWindowCloseCallback(GLWin, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				EventCommonNS::WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(GLWin, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					EventCommonNS::KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					EventCommonNS::KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					EventCommonNS::KeyPressedEvent event(key, true);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetCharCallback(GLWin, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				EventCommonNS::KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});

		glfwSetMouseButtonCallback(GLWin, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					EventCommonNS::MouseBtnPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					EventCommonNS::MouseBtnReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(GLWin, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				EventCommonNS::MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(GLWin, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				EventCommonNS::MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}

	void OpenGLWindows::Shutdown()
	{
		glfwDestroyWindow(m_WinService->GetGLFWindowsHandle());
		--s_GLFWWindowCount;

		//删除窗口
		if (s_GLFWWindowCount == 0 && m_WinService)
		{
			delete m_WinService;
		}
	}

	void OpenGLWindows::OnUpdate()
	{
		m_WinService->FlushWindow();
	}

	void OpenGLWindows::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool OpenGLWindows::IsVSync() const
	{
		return m_Data.VSync;
	}
}