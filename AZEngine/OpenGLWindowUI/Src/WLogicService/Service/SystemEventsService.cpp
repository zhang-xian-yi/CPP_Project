#include "SystemEventsService.h"

#include "OpenGLWindowUI/Src/IWindow.h"
#include "OpenGLWindowUI/Src/WLogicService/WindowsData.h"
#include "LayerCommon/Src/SysEvents.h"//系统事件

#include "GLFW/glfw3.h"
namespace WindowsNS
{
	/// <summary>
	/// 初始化系统事件的注册
	/// </summary>
	/// <param name="pGLWin"></param>
	void SystemEventsService::InitSysEventRegister(GLFWwindow* pGLWin)
	{
		// Set GLFW callbacks
		glfwSetWindowSizeCallback(pGLWin, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.WinPros.Width = width;
				data.WinPros.Height = height;

				LayerCommonNS::WindowResizeEvent eve(width, height);
				data.EventCallback(eve);
			});

		//窗口关闭事件
		glfwSetWindowCloseCallback(pGLWin, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				LayerCommonNS::WindowCloseEvent event;
				data.EventCallback(event);
			});

		//按钮事件
		glfwSetKeyCallback(pGLWin, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					LayerCommonNS::KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					LayerCommonNS::KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					LayerCommonNS::KeyPressedEvent event(key, true);
					data.EventCallback(event);
					break;
				}
				}
			});

		//字符串
		glfwSetCharCallback(pGLWin, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				LayerCommonNS::KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});

		//鼠标按钮
		glfwSetMouseButtonCallback(pGLWin, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					LayerCommonNS::MouseBtnPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					LayerCommonNS::MouseBtnReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				}
			});

		//鼠标滚动
		glfwSetScrollCallback(pGLWin, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				LayerCommonNS::MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		//设置焦点位置
		glfwSetCursorPosCallback(pGLWin, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				LayerCommonNS::MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});

	}

}

