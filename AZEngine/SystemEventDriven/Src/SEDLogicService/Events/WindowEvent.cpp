#include "WindowEvent.h"

namespace SysEventDNS
{
	/*------------------------------------------------------------------------------------*/
	WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height)
		: m_width(width), m_height(height)
	{

	}
	//��ȡ������չ�ĳߴ�
	unsigned int WindowResizeEvent::GetWidth() const
	{ 
		return m_width; 
	}

	unsigned int WindowResizeEvent::GetHeight() const
	{ 
		return m_height; 
	}
	/*------------------------------------------------------------------------------------*/
}