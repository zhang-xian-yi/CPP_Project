#pragma once

namespace SysEventDNS
{
	//确保事件的唯一特性
	enum class ESysEventId:unsigned int
	{
		None = 0,
		KeyBoardPress= 100,
		KeyBoardRelease,
		MouseMove = 200, 
		MousePress, MouseRelease, MouseScroll,WindowResize, WindowMove, WindowClose, 
		ApplicationUpdate = 500, 
		ApplicationRender
	};

	//所有事件都必须继承的父类
	class IEvent
	{

	protected:
		bool m_isHandle;//是否处理--决定事件是否继续传递
		ESysEventId m_eId;//决定事件由谁处理
	};

	/// <summary>
	/// 负责链接事件ID和事件处理函数
	/// </summary>
	class IConnect
	{
	public:
		virtual bool Connect();
	};


}