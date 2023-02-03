#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "IEvent.h"
namespace SysEventDNS
{
	class SysEventNSAPI AppTickEvent : public IEvent
	{
	public:
		AppTickEvent();

		DEF_EVENT_TYPE(AppTick)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//Ӧ�ø���
	class SysEventNSAPI AppUpdateEvent : public IEvent
	{
	public:
		AppUpdateEvent();

		DEF_EVENT_TYPE(AppUpdate)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//Ӧ����Ⱦ
	class SysEventNSAPI AppRenderEvent : public IEvent
	{
	public:
		AppRenderEvent();

		DEF_EVENT_TYPE(AppRender)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}