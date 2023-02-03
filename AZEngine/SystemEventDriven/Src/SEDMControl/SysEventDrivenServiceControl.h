#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "ISystemEvent.h"

namespace SysEventDNS
{
	class SysEventService;//前置声明

	/// <summary>
	/// 游戏引擎的业务逻辑控制器
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
		//IConnect 接口实现
		virtual bool Connect(ESysEventId eId, EventHandler handler);
		//IDispatch 接口实现
		virtual bool DispatchEvent(IEvent* eve);

	private:
		SysEventService* m_pSysEveService;
	};

}

