#include "MouseEvent.h"
namespace SysEventDNS
{
	/*------------------------------------------------------------------------------------*/
	MouseMovedEvent::MouseMovedEvent(const float x, const float y)
		: m_mouseX(x), m_mouseY(y) 
	{
	}

	float MouseMovedEvent::GetX() const
	{
		return m_mouseX;
	}
	float MouseMovedEvent::GetY() const
	{
		return m_mouseY;
	}
	/*------------------------------------------------------------------------------------*/

	MouseScrolledEvent::MouseScrolledEvent(const float xOffset, const float yOffset)
		: m_xOffset(xOffset), m_yOffset(yOffset)
	{
	}

	float MouseScrolledEvent::GetXOffset() const
	{
		return m_xOffset;
	}
	float MouseScrolledEvent::GetYOffset() const
	{
		return m_yOffset;
	}

	/*------------------------------------------------------------------------------------*/
	MouseCode MouseBtnEvent::GetMouseButton() const
	{
		 return m_btnCode; 
	}
	/*------------------------------------------------------------------------------------*/
	MouseBtnPressedEvent::MouseBtnPressedEvent(const MouseCode button)
		: MouseBtnEvent(button)
	{
	}
	/*------------------------------------------------------------------------------------*/
	MouseBtnReleasedEvent::MouseBtnReleasedEvent(const MouseCode button)
		: MouseBtnEvent(button)
	{
	}
}