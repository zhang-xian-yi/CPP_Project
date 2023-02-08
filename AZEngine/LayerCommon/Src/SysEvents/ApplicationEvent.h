#pragma once
#include "LayerCommon/Src/LCCommon/LCExpMarcoDefine.h"
#include "LayerCommon/Src/LCCommon/LCCore.h"
#include "LayerCommon/Src/SysEvents/ISysEvent.h" //外部模块会引用此文件，不能使用模块内部相对路径
namespace LayerCommonNS
{
	class LayerCommonNSAPI AppTickEvent : public ISysEvent
	{
	public:
		AppTickEvent();

		DEF_EVENT_TYPE(AppTick)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//应用更新
	class LayerCommonNSAPI AppUpdateEvent : public ISysEvent
	{
	public:
		AppUpdateEvent();

		DEF_EVENT_TYPE(AppUpdate)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//应用渲染
	class LayerCommonNSAPI AppRenderEvent : public ISysEvent
	{
	public:
		AppRenderEvent();

		DEF_EVENT_TYPE(AppRender)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}