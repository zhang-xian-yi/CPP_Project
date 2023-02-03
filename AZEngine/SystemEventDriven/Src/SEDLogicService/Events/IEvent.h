#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "SEDCommon/SEDCore.h"
namespace SysEventDNS
{
	//确保事件的唯一特性
	enum class SysEventNSAPI ESysEventId :unsigned short
	{
		None = 0,
		KeyPress,KeyRelease, KeyTyped,
		MouseMoved, MouseScrolled, MouseBtnPressed, MouseBtnReleased, 
		WindowResize, WindowMove, WindowClose,
		//
		AppTick, AppUpdate, AppRender
	};
	//描述时间的类型位， 通过占据二进制位判断某一类时间是否相等
	enum SysEventNSAPI ESysEventCategory:unsigned int
	{
		None = 0,
		EventCategoryApplication = LBit1(0),
		EventCategoryInput = LBit1(1),
		EventCategoryKeyboard = LBit1(2),
		EventCategoryMouse = LBit1(3),
		EventCategoryMouseButton = LBit1(4)

	};

	//所有事件都必须继承的父类
	class SysEventNSAPI IEvent
	{
	public:
		bool IsHandle;// 是否被处理
	public:
		virtual ~IEvent() = default;
		virtual ESysEventId GetEventId() const = 0;
		virtual int  GetCategoryFlags() const = 0;
		inline  bool IsInCategory(ESysEventCategory category){ return (GetCategoryFlags() & category); }
	};
}