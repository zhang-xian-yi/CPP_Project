#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "ISystemEvent.h"

namespace EventDrivenSysNS
{
	class SysEventService;//前置声明

	/// <summary>
	/// 游戏引擎的业务逻辑控制器
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
		//IConnect 接口实现
		virtual bool Connect(EventCommonNS::ESysEventId eId, EventHandler handler) override;
		//IDispatch 接口实现
		virtual bool DispatchEvent(EventCommonNS::ISysEvent& eve) override;

	private:
		SysEventService* m_pSysEveService;
	};

}

