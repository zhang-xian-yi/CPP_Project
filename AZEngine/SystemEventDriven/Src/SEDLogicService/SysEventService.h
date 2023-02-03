#pragma once
#include <unordered_map>
#include <list>
#include "SystemEventDriven/Src/ISystemEvent.h"
namespace SysEventDNS
{
	/// <summary>
	/// �ṩϵͳ�¼��ķ���
	/// </summary>
	class SysEventService
	{
	public:
		SysEventService();
		~SysEventService();

	private:
		std::unordered_map<ESysEventId, std::list<EventHandler>>* m_pEventHandlerMap;
	};
}


