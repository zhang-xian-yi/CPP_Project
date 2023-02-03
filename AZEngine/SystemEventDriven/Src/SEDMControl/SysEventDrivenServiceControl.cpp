#include "SysEventDrivenServiceControl.h"
#include "SystemEventDriven/Src/SEDLogicService/SysEventService.h"
namespace SysEventDNS
{
	SysEventDrivenServiceControl::SysEventDrivenServiceControl()
		:m_pSysEveService(new SysEventService())
	{
	}

	SysEventDrivenServiceControl::~SysEventDrivenServiceControl()
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
	bool SysEventDrivenServiceControl::Connect(ESysEventId eId, EventHandler handler)
	{
		return m_pSysEveService->BindEventHandlerList(eId, handler.func);
	}

	/// <summary>
	/// 派分事件
	/// </summary>
	/// <param name="eve"></param>
	/// <returns></returns>
	bool SysEventDrivenServiceControl::DispatchEvent(IEvent* eve)
	{
		ESysEventId id = eve->GetEventId();
		//处理事件
		return m_pSysEveService->HandleEvent(id, eve);
	}

	

}

