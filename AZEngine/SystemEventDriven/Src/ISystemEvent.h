#pragma once

namespace SysEventDNS
{
	/// <summary>
	/// 确保事件的调用函数一致     
	/// </summary>
	enum class ESysEventType :unsigned short
	{
		None = 0,
		KeyBoardTyoe    =  127, //键盘类型 约定范围[1,127)
		MouseMoveType   =  255, //鼠标类型事件 约定范围[128,255)
		WindowsType     =  511, //窗口类型事件 约定范围[256,511)
		ApplicationType =  1023,	    //应用程序类型事件 约定范围[1024,--)
	};

	//确保事件的唯一特性
	enum class ESysEventId:unsigned int
	{
		None = 0,
		KeyBoardPress = 1,
		KeyBoardRelease,
		MouseMove = 256, 
		MousePress, MouseRelease, MouseScroll,WindowResize, WindowMove, WindowClose, 
		ApplicationUpdate = 513, 
		ApplicationRender
	};





}