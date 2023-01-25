#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace FuncScheduleNS
{
	//前置声明
	class FuncScheduleCtlPrivate;

	/// <summary>
	/// 处理模块调度的逻辑
	/// </summary>
	class FuncScheduleControl:public MdlCommonNS::IMdlService
	{
	public:
		FuncScheduleControl();
		~FuncScheduleControl();
	public:
		virtual std::unique_ptr<MdlCommonNS::ISysResponse> DoService(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
	private:
		//选择业务的分支
		std::unique_ptr<MdlCommonNS::ISysResponse> SwitchService(const std::unique_ptr<MdlCommonNS::ISysRequest> para );
	private:
		FuncScheduleCtlPrivate* m_pService;//具体实现的业务类指针
	};
}


