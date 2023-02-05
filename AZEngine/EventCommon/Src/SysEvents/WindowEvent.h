#pragma once
#include "EventCommon/Src/ECCommon/ECExpMarcoDefine.h"
#include "EventCommon/Src/ECCommon/ECCore.h"
#include "EventCommon/Src/SysEvents/IEvent.h" //�ⲿģ������ô��ļ�������ʹ��ģ���ڲ����·��

namespace EventCommonNS
{
	//���ڵ�����С
	class EventCMNNSAPI WindowResizeEvent : public IEvent
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
	class EventCMNNSAPI WindowCloseEvent : public IEvent
	{
	public:
		WindowCloseEvent() = default;

		DEF_EVENT_TYPE(WindowClose)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}