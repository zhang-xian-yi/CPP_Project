#pragma once
#include "EventCommon/Src/ECCommon/ECExpMarcoDefine.h"
#include "EventCommon/Src/ECCommon/ECCore.h"
#include "EventCommon/Src/SysEvents/IEvent.h" //外部模块会引用此文件，不能使用模块内部相对路径

namespace EventCommonNS
{
	//窗口调整大小
	class EventCMNNSAPI WindowResizeEvent : public IEvent
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
	class EventCMNNSAPI WindowCloseEvent : public IEvent
	{
	public:
		WindowCloseEvent() = default;

		DEF_EVENT_TYPE(WindowClose)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}