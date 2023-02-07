#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "ISystemEvent.h"

namespace EventDrivenSysNS
{
	class SysEventService;//ǰ������

	/// <summary>
	/// ��Ϸ�����ҵ���߼�������
	/// </summary>
	class EventDrivenSysServiceControl
		:public MdlCommonNS::IMdlService,
		 public EventDrivenSysNS::IConnect,
		 public EventDrivenSysNS::IDispatch
	{
	public:
		EventDrivenSysServiceControl();
		~EventDrivenSysServiceControl();

	public:
		//IConnect �ӿ�ʵ��
		virtual bool Connect(EventCommonNS::ESysEventId eId, EventHandler handler) override;
		//IDispatch �ӿ�ʵ��
		virtual bool DispatchEvent(EventCommonNS::ISysEvent& eve) override;

	private:
		SysEventService* m_pSysEveService;
	};

}

