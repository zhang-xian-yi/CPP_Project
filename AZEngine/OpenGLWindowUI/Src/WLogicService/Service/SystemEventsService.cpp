#include "SystemEventsService.h"

#include "OpenGLWindowUI/Src/IWindow.h"
#include "OpenGLWindowUI/Src/WLogicService/WindowsData.h"
#include "EventCommon/Src/SysEvents.h"//ϵͳ�¼�
#include "EventDrivenSystem/Src/ISystemEvent.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h" //����ģ������
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "GLFW/glfw3.h"
namespace WindowsNS
{
	void SystemEventsService::BindEventResponse(EventCommonNS::ESysEventId eid, EventDrivenSysNS::EventHandler& handle_t)
	{
		auto pEDS = MdlCommonNS::ServiceContainerSingle::GetInstance().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_EventDrivenSys_Type);
		EventDrivenSysNS::IConnect* pConnect = pEDS.value()->ConvertType<EventDrivenSysNS::IConnect*>();
		//����ע��
		pConnect->Connect(eid, handle_t);
	}

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

				EventCommonNS::WindowResizeEvent eve(width, height);
				data.EventCallback(eve);
			});

		//���ڹر��¼�
		glfwSetWindowCloseCallback(pGLWin, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				EventCommonNS::WindowCloseEvent event;
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

		//�ַ���
		glfwSetCharCallback(pGLWin, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				EventCommonNS::KeyTypedEvent event(keycode);
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

		//������
		glfwSetScrollCallback(pGLWin, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				EventCommonNS::MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		//���ý���λ��
		glfwSetCursorPosCallback(pGLWin, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				EventCommonNS::MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});

	}

}

