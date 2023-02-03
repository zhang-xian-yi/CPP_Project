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
	//应用更新
	class SysEventNSAPI AppUpdateEvent : public IEvent
	{
	public:
		AppUpdateEvent();

		DEF_EVENT_TYPE(AppUpdate)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//应用渲染
	class SysEventNSAPI AppRenderEvent : public IEvent
	{
	public:
		AppRenderEvent();

		DEF_EVENT_TYPE(AppRender)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}