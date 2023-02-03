#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "SEDCommon/SEDCore.h"
namespace SysEventDNS
{
	//ȷ���¼���Ψһ����
	enum class SysEventNSAPI ESysEventId :unsigned short
	{
		None = 0,
		KeyPress,KeyRelease, KeyTyped,
		MouseMoved, MouseScrolled, MouseBtnPressed, MouseBtnReleased, 
		WindowResize, WindowMove, WindowClose,
		//
		AppTick, AppUpdate, AppRender
	};
	//����ʱ�������λ�� ͨ��ռ�ݶ�����λ�ж�ĳһ��ʱ���Ƿ����
	enum SysEventNSAPI ESysEventCategory:unsigned int
	{
		None = 0,
		EventCategoryApplication = LBit1(0),
		EventCategoryInput = LBit1(1),
		EventCategoryKeyboard = LBit1(2),
		EventCategoryMouse = LBit1(3),
		EventCategoryMouseButton = LBit1(4)

	};

	//�����¼�������̳еĸ���
	class SysEventNSAPI IEvent
	{
	public:
		bool IsHandle;// �Ƿ񱻴���
	public:
		virtual ~IEvent() = default;
		virtual ESysEventId GetEventId() const = 0;
		virtual int  GetCategoryFlags() const = 0;
		inline  bool IsInCategory(ESysEventCategory category){ return (GetCategoryFlags() & category); }
	};
}