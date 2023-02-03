#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "ISystemEvent.h"

namespace SysEventDNS
{
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
		virtual bool Connect(ESysEventId eId, std::function<bool(IEvent*)> handler);
		//IDispatch �ӿ�ʵ��
		virtual void DispatchEvent(IEvent* eve);

	private:

	};

}

