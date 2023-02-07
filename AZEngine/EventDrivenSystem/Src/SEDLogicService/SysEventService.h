#pragma once
#include <unordered_map>
#include <list>
#include "EventDrivenSystem/Src/ISystemEvent.h"
namespace EventDrivenSysNS
{
	class BEventFunc;//声明所有事件处理函数的基类

	/// <summary>
	/// 提供系统事件的服务
	/// </summary>
	class SysEventService
	{
	public:
		SysEventService();
		~SysEventService();

	public:
		//绑定事件ID 和事件处理函数的联系
		bool BindEventHandlerList(EventCommonNS::ESysEventId eveId, BEventFunc* eFunc);
		//处理事件
		BEventFunc* GetEventFunc(EventCommonNS::ESysEventId eveId);
	private:
		std::unordered_map<EventCommonNS::ESysEventId, BEventFunc*>* m_pEventHandlerMap;
	};
}


