#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace FuncScheduleNS
{
	//前置声明
	class CmdScheduleCtlPrivate;

	/// <summary>
	/// 处理模块调度的逻辑
	/// </summary>
	class FuncScheduleControl:public MdlCommonNS::IMdlService
	{
	public:
		FuncScheduleControl();
		~FuncScheduleControl();
	public:
		virtual MdlCommonNS::ISysResponse* DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para = nullptr) override;
	private:
		CmdScheduleCtlPrivate* m_pCmdCtl;//具体实现的业务类指针
	};
}


