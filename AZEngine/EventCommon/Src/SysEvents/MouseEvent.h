#pragma once
#include "EventCommon/Src/ECCommon/ECExpMarcoDefine.h"
#include "EventCommon/Src/ECCommon/ECCore.h"
#include "EventCommon/Src/SysEvents/IEvent.h" //外部模块会引用此文件，不能使用模块内部相对路径
namespace EventCommonNS
{
	//定义鼠标
	using MouseCode = unsigned short;
	namespace Mouse
	{
		enum : MouseCode
		{
			// From glfw3.h
			Button0 = 0,
			Button1 = 1,
			Button2 = 2,
			Button3 = 3,
			Button4 = 4,
			Button5 = 5,
			Button6 = 6,
			Button7 = 7,

			ButtonLast = Button7,
			ButtonLeft = Button0,
			ButtonRight = Button1,
			ButtonMiddle = Button2
		};
	}

	//鼠标移动事件
	class EventCMNNSAPI MouseMovedEvent : public IEvent
	{
	public:
		MouseMovedEvent(const float x, const float y);
			

		float GetX() const;
		float GetY() const;

		DEF_EVENT_TYPE(MouseMoved)
		DEF_EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_mouseX;
		float m_mouseY;
	};
	//鼠标滚动事件
	class EventCMNNSAPI MouseScrolledEvent : public IEvent
	{
	public:
		MouseScrolledEvent(const float xOffset, const float yOffset);		
		float GetXOffset() const;
		float GetYOffset() const;

		DEF_EVENT_TYPE(MouseScrolled)
		DEF_EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_xOffset;
		float m_yOffset;
	};

	//鼠标按钮
	class EventCMNNSAPI MouseBtnEvent : public IEvent
	{
	public:
		MouseCode GetMouseButton() const;

		DEF_EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
	protected:
		MouseBtnEvent(const MouseCode code)
			: m_btnCode(code) {}

		MouseCode m_btnCode;
	};

	//鼠标按钮按下
	class EventCMNNSAPI MouseBtnPressedEvent : public MouseBtnEvent
	{
	public:
		MouseBtnPressedEvent(const MouseCode button);
			

		DEF_EVENT_TYPE(MouseBtnPressed)
	};

	//鼠标按钮释放
	class EventCMNNSAPI MouseBtnReleasedEvent : public MouseBtnEvent
	{
	public:
		MouseBtnReleasedEvent(const MouseCode button);
			

		DEF_EVENT_TYPE(MouseBtnReleased)
	};
}