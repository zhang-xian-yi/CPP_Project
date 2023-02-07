#pragma once
#include "EventCommon/Src/ECCommon/ECExpMarcoDefine.h"
#include "EventCommon/Src/ECCommon/ECCore.h"
#include "EventCommon/Src/SysEvents/ISysEvent.h" //�ⲿģ������ô��ļ�������ʹ��ģ���ڲ����·��
namespace EventCommonNS
{
	class EventCMNNSAPI AppTickEvent : public ISysEvent
	{
	public:
		AppTickEvent();

		DEF_EVENT_TYPE(AppTick)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//Ӧ�ø���
	class EventCMNNSAPI AppUpdateEvent : public ISysEvent
	{
	public:
		AppUpdateEvent();

		DEF_EVENT_TYPE(AppUpdate)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//Ӧ����Ⱦ
	class EventCMNNSAPI AppRenderEvent : public ISysEvent
	{
	public:
		AppRenderEvent();

		DEF_EVENT_TYPE(AppRender)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}