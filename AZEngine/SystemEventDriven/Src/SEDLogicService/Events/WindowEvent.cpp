#include "WindowEvent.h"

namespace SysEventDNS
{
	/*------------------------------------------------------------------------------------*/
	WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height)
		: m_width(width), m_height(height)
	{

	}
	//获取重新扩展的尺寸
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