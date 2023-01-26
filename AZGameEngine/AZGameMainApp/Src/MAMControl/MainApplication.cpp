#include "MainApplication.h"
#include <memory>//内存
#include "FuncScheduleFactory.h"//模块调度工厂
#include "CMNServices/ServiceContainerSingle.h"
#include "CMNMEnum/ModuelType/EModuleType.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"//默认请求
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"//默认响应
#include "CMNMEnum/Command/ECommand.h"//执行命令的参数
namespace AZGameMainApp
{
	MainApplication::MainApplication()
	{
		
	}
	MainApplication::~MainApplication()
	{

	}

	/// <summary>
	/// 初始化运行环境
	/// </summary>
	void MainApplication::InitRunEnvirment()
	{
		bool ret = InitAllFunction();
	}
	/// <summary>
	/// 释放允许环境中的资源
	/// </summary>
	void MainApplication::StopRunEnvirment()
	{
		bool ret = StopAllFunction();

	}
	/// <summary>
	/// 初始化所有的功能模块
	/// </summary>
	bool MainApplication::InitAllFunction()
	{
		auto factory = FuncScheduleNS::FuncScheduleFactory::GetFactory();
		auto pMdlScheduleCtl = factory->CreateModuleInstance();
		//初始化所有的功能模块-默认参数为空
		auto mdlInitRep = pMdlScheduleCtl->ConstructModule();
		auto pServiceScheduleCtl = factory->CreateServiceInstance();
		//构造参数
		std::any cmd = std::make_any<MdlCommonNS::ECommand>(MdlCommonNS::ECommand::E_InitAllFunction);
		auto pRequest = new MdlCommonNS::DefSysRequest(cmd);
		//执行E_InitAllFunction 命令
		auto cmdReq = std::unique_ptr<MdlCommonNS::ISysRequest>(pRequest);
		auto mdlServiceRep = pServiceScheduleCtl->DoService(cmdReq);
		std::any& repInfo = mdlServiceRep->GetData();
		if (repInfo.has_value())
		{
			//返回初始化的响应并强制转换为bool 类型，确保初始化正常
			bool flag = std::any_cast<bool>(repInfo);
			//必须确定flag的值之后才能返回
			return flag;
		}

		delete mdlServiceRep;//释放响应数据
		return true;
	}

	bool MainApplication::StopAllFunction()
	{
		auto pServiceOptional = MdlCommonNS::ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_FuncSchedule_Type);
		if (pServiceOptional.has_value())
		{
			//构造参数		
			std::any cmd = std::make_any<MdlCommonNS::ECommand>(MdlCommonNS::ECommand::E_DestoryAllFunction);
			auto pRequest = new MdlCommonNS::DefSysRequest(cmd);
			//执行E_InitAllFunction 命令
			auto cmdReq = std::unique_ptr<MdlCommonNS::ISysRequest>(pRequest);
			auto mdlServiceRep = pServiceOptional.value()->DoService(cmdReq);

			delete mdlServiceRep;//释放响应
		}
		return true;
	}
}