#pragma once

#include "SysEvents/ApplicationEvent.h"
#include "SysEvents/KeyboardEvent.h"
#include "SysEvents/MouseEvent.h"
#include "SysEvents/WindowEvent.h"
namespace LayerCommonNS
{
	class EventDispatcher
	{
	public:
		EventDispatcher(ISysEvent& event)
			: m_Event(event)
		{
		}
		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventId() == T::GetStaticType())
			{
				m_Event.IsHandle |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		ISysEvent& m_Event;
	};
}
