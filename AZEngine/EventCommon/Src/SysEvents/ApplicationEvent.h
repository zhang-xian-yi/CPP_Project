#pragma once
#include "EventCommon/Src/ECCommon/ECExpMarcoDefine.h"
#include "EventCommon/Src/ECCommon/ECCore.h"
#include "EventCommon/Src/SysEvents/IEvent.h" //�ⲿģ������ô��ļ�������ʹ��ģ���ڲ����·��
namespace EventCommonNS
{
	class EventCMNNSAPI AppTickEvent : public IEvent
	{
	public:
		AppTickEvent();

		DEF_EVENT_TYPE(AppTick)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//Ӧ�ø���
	class EventCMNNSAPI AppUpdateEvent : public IEvent
	{
	public:
		AppUpdateEvent();

		DEF_EVENT_TYPE(AppUpdate)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//Ӧ����Ⱦ
	class EventCMNNSAPI AppRenderEvent : public IEvent
	{
	public:
		AppRenderEvent();

		DEF_EVENT_TYPE(AppRender)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}