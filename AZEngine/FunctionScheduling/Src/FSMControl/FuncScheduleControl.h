#pragma once
#include "CMNInterface/IMdlService.h"
#include "IFuncSchedule.h"

namespace FuncScheduleNS
{
	//前置声明
	class CmdScheduleCtlPrivate;

	/// <summary>
	/// 处理模块调度的逻辑
	/// </summary>
	class FuncScheduleControl:public MdlCommonNS::IMdlService,public FuncScheduleNS::IFuncSchedule
	{
	public:
		FuncScheduleControl();
		~FuncScheduleControl();
	public:
		std::any ExecuteCmd(MdlCommonNS::ECommand cmd)override;
	private:
		CmdScheduleCtlPrivate* m_pCmdCtl;//具体实现的业务类指针
	};
}


