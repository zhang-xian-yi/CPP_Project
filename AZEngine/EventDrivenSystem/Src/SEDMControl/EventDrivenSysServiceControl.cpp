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
	/// �����¼�ID���¼�������
	/// </summary>
	/// <param name="eId">�¼�id</param>
	/// <param name="handler">�¼�������</param>
	/// <returns></returns>
	bool EventDrivenSysServiceControl::Connect(ESysEventId eId, EventHandler handler)
	{
		return m_pSysEveService->BindEventHandlerList(eId, handler.func);
	}

	/// <summary>
	/// �ɷ��¼�
	/// </summary>
	/// <param name="eve"></param>
	/// <returns></returns>
	bool EventDrivenSysServiceControl::DispatchEvent(IEvent& eve)
	{
		//�����¼�
		return m_pSysEveService->HandleEvent(eve);
	}

	

}

