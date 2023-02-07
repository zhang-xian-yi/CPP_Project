#pragma once


//前置声明 
struct GLFWwindow;//from  glew第三方库， 不能将此声明放入命名空间中
namespace EventDrivenSysNS
{

	struct EventHandler;//事件处理的结构体
}

namespace EventCommonNS
{
	enum class ESysEventId :unsigned short;//系统事件id
}

namespace WindowsNS
{
	/// <summary>
	/// 系统事件服务
	/// </summary>
	class SystemEventsService
	{
	public:
		SystemEventsService() = default;
		~SystemEventsService() = default;

	public:
		//注册Glfw 与openggl窗口质检的事件捕捉
		void InitSysEventRegister(GLFWwindow* pGLWin);
		//绑定事件处理机制
		void BindEventResponse(EventCommonNS::ESysEventId eid, EventDrivenSysNS::EventHandler& handle_t);
	};
}