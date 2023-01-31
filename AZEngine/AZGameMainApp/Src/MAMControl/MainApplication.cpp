#include "MainApplication.h"
#include <memory>//内存
#include "FuncScheduleFactory.h"//模块调度工厂
#include "IFuncSchedule.h"
#include "CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "CMNMEnum/ModuelType/EModuleType.h"
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

		auto pService = pServiceScheduleCtl->ConvertType<FuncScheduleNS::IFuncSchedule*>();
		std::any mdlServiceRep = pService->ExecuteCmd(MdlCommonNS::ECommand::E_InitAllFunction);
		if (mdlServiceRep.has_value())
		{
			//返回初始化的响应并强制转换为bool 类型，确保初始化正常
			//响应与初始化完成正常
			std::tuple<bool, std::string> flag = std::any_cast<std::tuple<bool, std::string>>(mdlServiceRep);
			//必须确定flag的值之后才能返回
			return std::get<0>(flag);
		}
		return false;
	}

	bool MainApplication::StopAllFunction()
	{
		auto pServiceOptional = MdlCommonNS::ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_FuncSchedule_Type);
		if (pServiceOptional.has_value())
		{
			auto pService = pServiceOptional.value()->ConvertType<FuncScheduleNS::IFuncSchedule*>();
			//构造参数		
			std::any stopRep = pService->ExecuteCmd(MdlCommonNS::ECommand::E_DestoryAllFunction);
			//返回初始化的响应并强制转换为bool 类型，确保初始化正常
			std::tuple<bool, std::string> flag = std::any_cast<std::tuple<bool, std::string>>(stopRep);
			//必须确定flag的值之后才能返回
			return std::get<0>(flag);
		}
		return false;
	}
}