#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "SEDCommon/SEDCore.h"
#include "IEvent.h"
namespace SysEventDNS
{
	//�������
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

	//����ƶ��¼�
	class SysEventNSAPI MouseMovedEvent : public IEvent
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
	//�������¼�
	class SysEventNSAPI MouseScrolledEvent : public IEvent
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

	//��갴ť
	class SysEventNSAPI MouseBtnEvent : public IEvent
	{
	public:
		MouseCode GetMouseButton() const;

		DEF_EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
	protected:
		MouseBtnEvent(const MouseCode code)
			: m_btnCode(code) {}

		MouseCode m_btnCode;
	};

	//��갴ť����
	class SysEventNSAPI MouseBtnPressedEvent : public MouseBtnEvent
	{
	public:
		MouseBtnPressedEvent(const MouseCode button);
			

		DEF_EVENT_TYPE(MouseBtnPressed)
	};

	//��갴ť�ͷ�
	class SysEventNSAPI MouseBtnReleasedEvent : public MouseBtnEvent
	{
	public:
		MouseBtnReleasedEvent(const MouseCode button);
			

		DEF_EVENT_TYPE(MouseBtnReleased)
	};
}