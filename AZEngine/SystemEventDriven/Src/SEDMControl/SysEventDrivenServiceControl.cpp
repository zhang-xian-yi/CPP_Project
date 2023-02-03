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
	/// �����¼�ID���¼�������
	/// </summary>
	/// <param name="eId">�¼�id</param>
	/// <param name="handler">�¼�������</param>
	/// <returns></returns>
	bool SysEventDrivenServiceControl::Connect(ESysEventId eId, EventHandler handler)
	{
		return m_pSysEveService->BindEventHandlerList(eId, handler.func);
	}

	/// <summary>
	/// �ɷ��¼�
	/// </summary>
	/// <param name="eve"></param>
	/// <returns></returns>
	bool SysEventDrivenServiceControl::DispatchEvent(IEvent* eve)
	{
		ESysEventId id = eve->GetEventId();
		//�����¼�
		return m_pSysEveService->HandleEvent(id, eve);
	}

	

}

