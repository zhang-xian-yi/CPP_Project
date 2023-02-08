#include "KeyboardEvent.h"

namespace LayerCommonNS
{
	/*------------------------------------------------------------------------------------*/
	KeyPressedEvent::KeyPressedEvent(const KeyCode keycode, bool isRepeat)
		: KeyEvent(keycode), m_IsRepeat(isRepeat)
	{
	}
	bool KeyPressedEvent::IsRepeat() const
	{
		 return m_IsRepeat;
	}
	/*------------------------------------------------------------------------------------*/
	KeyTypedEvent::KeyTypedEvent(const KeyCode keycode)
		: KeyEvent(keycode)
	{
	}
	/*------------------------------------------------------------------------------------*/
	KeyReleasedEvent::KeyReleasedEvent(const KeyCode keycode)
		: KeyEvent(keycode)
	{
	}

	KeyCode KeyEvent::GetKeyCode() const
	{
		return m_KeyCode;
	}

}
