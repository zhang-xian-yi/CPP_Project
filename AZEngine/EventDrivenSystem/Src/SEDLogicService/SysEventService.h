#pragma once
#include <unordered_map>
#include <list>
#include "EventDrivenSystem/Src/ISystemEvent.h"
namespace SysEventDNS
{
	using namespace EventCommonNS;

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
		bool BindEventHandlerList(ESysEventId eveId, EveHandlerFN handler);
		//处理事件
		bool HandleEvent(IEvent& pEve);
	private:
		std::unordered_map<ESysEventId, std::list<EveHandlerFN>*>* m_pEventHandlerMap;
	};
}


