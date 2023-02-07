#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "ISystemEvent.h"

namespace EventDrivenSysNS
{
	class BEventFunc;//���������¼��������Ļ���
	class SysEventService;//ϵͳ�¼�����

	/// <summary>
	/// ��Ϸ�����ҵ���߼�������
	/// </summary>
	class EventDrivenSysServiceControl
		:public MdlCommonNS::IMdlService,
		 public EventDrivenSysNS::IRegister,
		 public EventDrivenSysNS::IDispatch
	{
	public:
		EventDrivenSysServiceControl();
		~EventDrivenSysServiceControl();

	public:
		//IConnect �ӿ�ʵ��
		virtual bool RegisterPrivate(EventCommonNS::ESysEventId eid, BEventFunc* eFunc) override;
		//IDispatch �ӿ�ʵ��
		virtual BEventFunc* GetEventFunc(EventCommonNS::ESysEventId eid) override;
	private:
		SysEventService* m_pSysEveService;
	};

}

