#pragma once
#include "LayerCommon/Src/LCCommon/LCExpMarcoDefine.h"
#include "LayerCommon/Src/LCCommon/LCCore.h"
#include "LayerCommon/Src/SysEvents/ISysEvent.h" //外部模块会引用此文件，不能使用模块内部相对路径

namespace LayerCommonNS
{
	//窗口调整大小
	class LayerCommonNSAPI WindowResizeEvent : public ISysEvent
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height);
		//获取重新扩展的尺寸
		unsigned int GetWidth() const;
		unsigned int GetHeight() const;

		DEF_EVENT_TYPE(WindowResize)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	//窗口关闭
	class LayerCommonNSAPI WindowCloseEvent : public ISysEvent
	{
	public:
		WindowCloseEvent() = default;

		DEF_EVENT_TYPE(WindowClose)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}