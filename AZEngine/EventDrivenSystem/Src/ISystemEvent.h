#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "EventCommon/Src/SysEvents/IEvent.h"
#include "EventCommon/Src/SysEvents.h"

namespace EventDrivenSysNS
{
	typedef bool (*EveHandlerFN)(EventCommonNS::IEvent&);

	struct EventHandler
	{
		EveHandlerFN func;
	};

	/// <summary>
	/// 负责链接事件ID和事件处理函数
	/// </summary>
	class EventDrivenSysNSAPI IConnect
	{
	public:
		virtual bool Connect(EventCommonNS::ESysEventId eId, EventHandler handler) = 0;
	};

	/// <summary>
	/// 负责转发事件
	/// </summary>
	class EventDrivenSysNSAPI IDispatch
	{
	public:
		virtual bool DispatchEvent(EventCommonNS::IEvent& eve) = 0;
	};
}