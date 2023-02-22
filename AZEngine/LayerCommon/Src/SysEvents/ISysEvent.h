#pragma once
#include "LayerCommon/Src/LCCommon/LCExpMarcoDefine.h"
#include "LayerCommon/Src/LCCommon/LCCore.h"
namespace LayerCommonNS
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
	class LayerCommonNSAPI ISysEvent
	{
	public:
		bool IsHandle = false;// �Ƿ񱻴���
	public:
		virtual ~ISysEvent() = default;
		virtual ESysEventId GetEventId() const = 0;
		virtual int  GetCategoryFlags() const = 0;
		virtual const char* GetName()const = 0;//��ȡ�¼�����
		inline  bool IsInCategory(ESysEventCategory category){ return (GetCategoryFlags() & category); }
	};
}