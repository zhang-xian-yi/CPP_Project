#pragma once
#include "EventCommon/Src/ECCommon/ECExpMarcoDefine.h"
#include "EventCommon/Src/ECCommon/ECCore.h"
#include "EventCommon/Src/SysEvents/ISysEvent.h" //外部模块会引用此文件，不能使用模块内部相对路径
namespace EventCommonNS
{
	class EventCMNNSAPI AppTickEvent : public ISysEvent
	{
	public:
		AppTickEvent();

		DEF_EVENT_TYPE(AppTick)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//应用更新
	class EventCMNNSAPI AppUpdateEvent : public ISysEvent
	{
	public:
		AppUpdateEvent();

		DEF_EVENT_TYPE(AppUpdate)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//应用渲染
	class EventCMNNSAPI AppRenderEvent : public ISysEvent
	{
	public:
		AppRenderEvent();

		DEF_EVENT_TYPE(AppRender)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}