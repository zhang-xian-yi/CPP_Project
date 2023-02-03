#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "IEvent.h"
namespace SysEventDNS
{
	//���ڵ�����С
	class SysEventNSAPI WindowResizeEvent : public IEvent
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height);
		//��ȡ������չ�ĳߴ�
		unsigned int GetWidth() const;
		unsigned int GetHeight() const;

		DEF_EVENT_TYPE(WindowResize)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	//���ڹر�
	class SysEventNSAPI WindowCloseEvent : public IEvent
	{
	public:
		WindowCloseEvent() = default;

		DEF_EVENT_TYPE(WindowClose)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}