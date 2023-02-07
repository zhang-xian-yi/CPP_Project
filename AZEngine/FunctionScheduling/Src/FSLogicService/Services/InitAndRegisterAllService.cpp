#include "InitAndRegisterAllService.h"
#include <future>//异步执行头文件
#include <thread>
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"//模块重要接口
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"//模块类型
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "Logger/Src/ILogger.h"
#include "Logger/Src/LoggerFactory.h"//日志工厂类
#include "FunctionScheduling/Src/FuncScheduleFactory.h"//模块调度工厂类
#include "OpenGLWindowUI/Src/OpenGLWindowsFactory.h"//OPenglUI的工厂类
#include "AZDataCompute/Src/DataComputeFactory.h"//数据计算中心类
#include "EventDrivenSystem/Src/EventDrivenSysFactory.h"//
namespace FuncScheduleNS
{
	using namespace MdlCommonNS;

	void InitAndRegisterAllService::DoService()
	{
		IMdlFactory* pFactory = nullptr;
		//初始化/注册日志实例
		pFactory = LoggerNS::LoggerFactory::GetFactory();
		InitAndRegisterMdl(EModuleType::E_Logger_Type, pFactory);
		//初始化/注册窗口实例
		pFactory = WindowsNS::OpenGLWindowsFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_OpenGLWindow_Type, pFactory);
		//初始化/注册数据计算实例
		pFactory = AZDataComputeNS::DataComputeFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_DataCompute_Type, pFactory);
		//初始化/注册系统事件驱动实例
		pFactory = EventDrivenSysNS::EventDrivenSysFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_SysEventDriven_Type, pFactory);
	}
	/// <summary>
	/// 异步执行任务
	/// </summary>
	/// <param name="type"></param>
	/// <param name="factory"></param>
	void InitAndRegisterAllService::InitAndRegisterMdlAsync(MdlCommonNS::EModuleType type, MdlCommonNS::IMdlFactory* factory)
	{
		auto result = std::async(&InitAndRegisterAllService::InitAndRegisterMdl, this, type, factory); // (2) async call 

		//TODO 需要在全局变量域中标记“type”模块已经进行初始化
		bool initFlag = result.get();

	}

	/// <summary>
	/// 初始化和注册的真实业务逻辑
	/// </summary>
	/// <param name="type"></param>
	/// <param name="factory"></param>
	/// <returns></returns>
	bool InitAndRegisterAllService::InitAndRegisterMdl(MdlCommonNS::EModuleType type, MdlCommonNS::IMdlFactory* factory)
	{

		try
		{
			//注意此处构建的是new 对象， 需要添加智能指针进行管理
			MdlCommonNS::IMdlOperat* pMdl = factory->CreateModuleInstance();
			MdlCommonNS::IMdlService* pService = factory->CreateServiceInstance();
			//初始化模块
			bool rep = pMdl->ConstructModule();
		
			//注册模块
			ServiceContainerSingle::GetContainer().RegisterModuleInterface(type, pMdl, pService);
			//进行日志打印，注意日志模块必须最先注册且是同步
			std::string msg = MdlCommonNS::EnumModuleTypeExtend::GetInstance().GetMdlCnDesc(type) + "注册成功";
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV, msg);
			return rep;
		}
		catch (std::exception exp)
		{
			std::string userMsg = MdlCommonNS::EnumModuleTypeExtend::GetInstance().GetMdlCnDesc(type) + "注册失败";
			std::string expMsg  =  exp.what();
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, userMsg);
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, expMsg);
			//无论日志是否打印，均需要返回false
			return false;//初始化异常
		}
	}
}