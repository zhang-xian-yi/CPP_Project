#include "SystemEventsService.h"

#include "IWindow.h"
#include "WLogicService/WindowsData.h"
#include "LayerCommon/Src/SysEvents.h"//ϵͳ�¼�

#include "GLFW/glfw3.h"
namespace WindowsNS
{
	/// <summary>
	/// ��ʼ��ϵͳ�¼���ע��
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

		//���ڹر��¼�
		glfwSetWindowCloseCallback(pGLWin, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				LayerCommonNS::WindowCloseEvent event;
				data.EventCallback(event);
			});

		//��ť�¼�
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

		//�ַ���
		glfwSetCharCallback(pGLWin, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				LayerCommonNS::KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});

		//��갴ť
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

		//������
		glfwSetScrollCallback(pGLWin, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				LayerCommonNS::MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		//���ý���λ��
		glfwSetCursorPosCallback(pGLWin, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				LayerCommonNS::MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});

	}

}

