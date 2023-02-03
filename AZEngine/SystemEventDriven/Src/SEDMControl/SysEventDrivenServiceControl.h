#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "ISystemEvent.h"

namespace SysEventDNS
{
	class SysEventService;//ǰ������

	/// <summary>
	/// ��Ϸ�����ҵ���߼�������
	/// </summary>
	class SysEventDrivenServiceControl 
		:public MdlCommonNS::IMdlService,
		 public SysEventDNS::IConnect,
		 public SysEventDNS::IDispatch
	{
	public:
		SysEventDrivenServiceControl();
		~SysEventDrivenServiceControl();

	public:
		//IConnect �ӿ�ʵ��
		virtual bool Connect(ESysEventId eId, EventHandler handler);
		//IDispatch �ӿ�ʵ��
		virtual bool DispatchEvent(IEvent* eve);

	private:
		SysEventService* m_pSysEveService;
	};

}

