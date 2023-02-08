#include "EventDrivenSysServiceControl.h"
#include "EventDrivenSystem/Src/SEDLogicService/SysEventService.h"
namespace EventDrivenSysNS
{

	EventDrivenSysServiceControl::EventDrivenSysServiceControl()
		:m_pSysEveService(new SysEventService())
	{
	}

	EventDrivenSysServiceControl::~EventDrivenSysServiceControl()
	{
		if (m_pSysEveService)
		{
			delete m_pSysEveService;
			m_pSysEveService = nullptr;
		}
	}

	/// <summary>
	/// 链接事件ID和事件处理器
	/// </summary>
	/// <param name="eId">事件id</param>
	/// <param name="handler">事件处理器</param>
	/// <returns></returns>
	bool EventDrivenSysServiceControl::RegisterPrivate(LayerCommonNS::ESysEventId eid, BEventFunc* eFunc)
	{
		return m_pSysEveService->BindEventHandlerList(eid, eFunc);
	}

	/// <summary>
	/// 派分事件
	/// </summary>
	/// <param name="eve"></param>
	/// <returns></returns>
	BEventFunc* EventDrivenSysServiceControl::GetEventFunc(LayerCommonNS::ESysEventId eid)
	{
		//处理事件
		return m_pSysEveService->GetEventFunc(eid);
	}

	

}

