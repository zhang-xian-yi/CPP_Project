#pragma once
#include "LayerCommon/Src/LCCommon/LCExpMarcoDefine.h"
#include "LayerCommon/Src/LCCommon/LCCore.h"
#include "LayerCommon/Src/SysEvents/ISysEvent.h" //�ⲿģ������ô��ļ�������ʹ��ģ���ڲ����·��

namespace LayerCommonNS
{
	//���ڵ�����С
	class LayerCommonNSAPI WindowResizeEvent : public ISysEvent
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
	class LayerCommonNSAPI WindowCloseEvent : public ISysEvent
	{
	public:
		WindowCloseEvent() = default;

		DEF_EVENT_TYPE(WindowClose)
		DEF_EVENT_CATEGORY(EventCategoryApplication)
	};
}