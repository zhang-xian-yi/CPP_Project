#include "SysEventService.h"
namespace SysEventDNS
{
	SysEventService::SysEventService()
		:m_pEventHandlerMap(new std::unordered_map<ESysEventId, std::list<EventHandler>>())
	{
	}

	SysEventService::~SysEventService()
	{
		if (m_pEventHandlerMap)
		{
			delete m_pEventHandlerMap;
			m_pEventHandlerMap = nullptr;
		}
	}



}
