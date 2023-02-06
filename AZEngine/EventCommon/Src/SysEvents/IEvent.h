#pragma once
#include "EventCommon/Src/ECCommon/ECExpMarcoDefine.h"
#include "EventCommon/Src/ECCommon/ECCore.h"
namespace EventCommonNS
{
	//ȷ���¼���Ψһ����
	enum class ESysEventId :unsigned short
	{
		None = 0,
		KeyPress,KeyRelease, KeyTyped,
		MouseMoved, MouseScrolled, MouseBtnPressed, MouseBtnReleased, 
		WindowResize, WindowMove, WindowClose,
		//
		AppTick, AppUpdate, AppRender
	};
	//����ʱ�������λ�� ͨ��ռ�ݶ�����λ�ж�ĳһ��ʱ���Ƿ����
	enum ESysEventCategory:unsigned int
	{
		None = 0,
		EventCategoryApplication = LBit1(0),
		EventCategoryInput = LBit1(1),
		EventCategoryKeyboard = LBit1(2),
		EventCategoryMouse = LBit1(3),
		EventCategoryMouseButton = LBit1(4)

	};

	//�����¼�������̳еĸ���
	class EventCMNNSAPI IEvent
	{
	public:
		bool IsHandle;// �Ƿ񱻴���
	public:
		virtual ~IEvent() = default;
		virtual ESysEventId GetEventId() const = 0;
		virtual int  GetCategoryFlags() const = 0;
		virtual const char* GetName()const = 0;//��ȡ�¼�����
		inline  bool IsInCategory(ESysEventCategory category){ return (GetCategoryFlags() & category); }
	};
}