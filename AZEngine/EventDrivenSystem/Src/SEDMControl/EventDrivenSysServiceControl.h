#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "ISystemEvent.h"

namespace EventDrivenSysNS
{
	class BEventFunc;//声明所有事件处理函数的基类
	class SysEventService;//系统事件服务

	/// <summary>
	/// 游戏引擎的业务逻辑控制器
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
		//IConnect 接口实现
		virtual bool RegisterPrivate(EventCommonNS::ESysEventId eid, BEventFunc* eFunc) override;
		//IDispatch 接口实现
		virtual BEventFunc* GetEventFunc(EventCommonNS::ESysEventId eid) override;
	private:
		SysEventService* m_pSysEveService;
	};

}

