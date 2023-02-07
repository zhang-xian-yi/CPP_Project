#pragma once
#include <functional>
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "EventCommon/Src/SysEvents/ISysEvent.h"
#include "EventCommon/Src/SysEvents.h"

namespace EventDrivenSysNS
{
	typedef bool (*EveHandlerFN)(EventCommonNS::ISysEvent&);

	struct EventHandler
	{
		EveHandlerFN func;
	};

	/// <summary>
	/// ���������¼�ID���¼�������
	/// </summary>
	class EventDrivenSysNSAPI IConnect
	{
	public:
		virtual bool Connect(EventCommonNS::ESysEventId eId, EventHandler handler) = 0;
	};

	/// <summary>
	/// ����ת���¼�
	/// </summary>
	class EventDrivenSysNSAPI IDispatch
	{
	public:
		virtual bool DispatchEvent(EventCommonNS::ISysEvent& eve) = 0;
	};
}