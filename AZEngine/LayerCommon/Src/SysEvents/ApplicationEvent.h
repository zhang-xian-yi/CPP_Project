#pragma once
#include "LayerCommon/Src/LCCommon/LCExpMarcoDefine.h"
#include "LayerCommon/Src/LCCommon/LCCore.h"
#include "LayerCommon/Src/SysEvents/ISysEvent.h" //�ⲿģ������ô��ļ�������ʹ��ģ���ڲ����·��
namespace LayerCommonNS
{
	class LayerCommonNSAPI AppTickEvent : public ISysEvent
	{
	public:
		AppTickEvent();

		DEF_EVENT_TYPE(AppTick)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//Ӧ�ø���
	class LayerCommonNSAPI AppUpdateEvent : public ISysEvent
	{
	public:
		AppUpdateEvent();

		DEF_EVENT_TYPE(AppUpdate)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
	//Ӧ����Ⱦ
	class LayerCommonNSAPI AppRenderEvent : public ISysEvent
	{
	public:
		AppRenderEvent();

		DEF_EVENT_TYPE(AppRender)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}