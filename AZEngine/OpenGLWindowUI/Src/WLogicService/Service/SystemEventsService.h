#pragma once


//前置声明 
struct GLFWwindow;//from  glew第三方库， 不能将此声明放入命名空间中

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
		//初始化系统事件响应
		void InitSysEventRegister(GLFWwindow* pGLWin);

	};
}