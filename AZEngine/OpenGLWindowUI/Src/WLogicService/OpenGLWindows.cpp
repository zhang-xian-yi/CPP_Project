#include "OpenGLWindows.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"
#include "MdlCommon/Src/CMNMacro/TypeMacroDef.h"
#include "OpenGLWindowUI/Src/IWindow.h"
#include "Logger/Src/ILogger.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"//模块类型
#include "EventCommon/Src/SysEvents.h"//系统事件
namespace WindowsNS
{
	static uint8_t s_GLFWWindowCount = 0;

	OpenGLWindows::OpenGLWindows(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
	}

	/// <summary>
	/// 错误日志的回调函数
	/// </summary>
	/// <param name="error"></param>
	/// <param name="description"></param>
	static void GLFWErrorCallback(int error, const char* description)
	{
		FormatLog("GLFW Error({0}): {1}", error, description);
	}

	OpenGLWindows::~OpenGLWindows()
	{
		Shutdown();
	}

	void OpenGLWindows::Show()
	{
		FormatLog("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

		if (s_GLFWWindowCount == 0)
		{
			FormatLog("glfwInit");
			int success = glfwInit();
			FormatLog("{0} Could not initialize GLFW!", success);
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		{
			FormatLog("glfwCreateWindow");

			m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
			++s_GLFWWindowCount;
		}

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				EventCommonNS::WindowResizeEvent eve(width, height);
				data.EventCallback(eve);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				EventCommonNS::WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
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

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				EventCommonNS::KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
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

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				EventCommonNS::MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				EventCommonNS::MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}

	void OpenGLWindows::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		--s_GLFWWindowCount;

		if (s_GLFWWindowCount == 0)
		{
			glfwTerminate();
		}
	}

	void OpenGLWindows::OnUpdate()
	{
		glfwPollEvents();
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