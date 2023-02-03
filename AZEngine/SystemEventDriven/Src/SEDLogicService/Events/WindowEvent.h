#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "IEvent.h"
namespace SysEventDNS
{
	//窗口调整大小
	class SysEventNSAPI WindowResizeEvent : public IEvent
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
	class SysEventNSAPI WindowCloseEvent : public IEvent
	{
	public:
		WindowCloseEvent() = default;

		DEF_EVENT_TYPE(WindowClose)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}