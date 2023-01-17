#include "MainApplication.h"
#include <memory>//内存
#include "FuncScheduleFactory.h"//模块调度工厂

#include "CMNEntity/DefaultReqRep/DefSysRequest.h"//默认请求
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"//默认响应
#include "CMNEntity/Any.h"//任意类型的描述类
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
	/// 初始化所有的功能模块
	/// </summary>
	bool& MainApplication::InitAllFunction()
	{
		auto factory = FuncScheduleNS::FuncScheduleFactory::GetFactory();
		auto pMdlScheduleCtl = factory->CreateModuleInstance();
		//初始化所有的功能模块-默认参数为空
		auto mdlInitRep = pMdlScheduleCtl->ConstructModule();
		auto pServiceScheduleCtl = factory->CreateServiceInstance();
		//构造参数
		auto pRequest = new MdlCommonNS::DefSysRequest();
		MdlCommonNS::Any cmd = MdlCommonNS::ECommand::E_InitAllFunction;
		pRequest->SetData(cmd);
		//执行E_InitAllFunction 命令
		auto mdlServiceRep = pServiceScheduleCtl->DoService(std::unique_ptr<MdlCommonNS::ISysRequest>(pRequest));
		MdlCommonNS::Any& repInfo = mdlServiceRep->GetData();
		//返回初始化的响应并强制转换为bool 类型，确保初始化正常
		return repInfo.AnyRefCast<bool>();
		//return true;
	}
}