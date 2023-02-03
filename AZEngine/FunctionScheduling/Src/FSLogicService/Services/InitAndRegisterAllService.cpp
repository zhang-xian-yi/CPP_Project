#include "InitAndRegisterAllService.h"
#include <future>//异步执行头文件
#include <thread>
#include "CMNInterface/IMdlOperat.h"//模块操作接口
#include "CMNInterface/IMdlFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "CMNMEnum/ModuelType/EModuleType.h"//模块类型
#include "LoggerFactory.h"//日志工厂类
#include "ILogger.h"
#include "FuncScheduleFactory.h"//模块调度工厂类
#include "OpenGLUIFactory.h"//OPenglUI的工厂类
#include "GameEngineFactory.h"//游戏引擎工厂类
namespace FuncScheduleNS
{
	using namespace MdlCommonNS;

	void InitAndRegisterAllService::DoService()
	{
		IMdlFactory* pFactory = nullptr;
		//初始化/注册日志实例
		pFactory = LoggerNS::LoggerFactory::GetFactory();
		InitAndRegisterMdl(EModuleType::E_Logger_Type, pFactory);
		//初始化/注册游戏引擎实例
		pFactory = AZGameEngineNS::GameEngineFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_GameEngine_Type, pFactory);
		//初始化/注册OpenglUI实例
		pFactory = OpenGLUINS::OpenGLUIFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_OpengGLUI_Type, pFactory);
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
			auto iLogS = ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_Logger_Type);
			if (iLogS.has_value())
			{
				auto prunlog = iLogS.value()->ConvertType<LoggerNS::IFileLogger*>();
				prunlog->LogFileMsgAsync(LoggerNS::ELogLevel::E_Info_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance()->GetMdlCnDesc(type)+"注册成功");
				auto pstdoutlog = iLogS.value()->ConvertType<LoggerNS::IStdoutLogger*>();
				pstdoutlog->LogStdoutMsgAsync(LoggerNS::ELogLevel::E_Info_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance()->GetMdlCnDesc(type) + "注册成功");
			}
			return rep;
		}
		catch (std::exception exp)
		{
			auto iLogS = ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_Logger_Type);
			if (iLogS.has_value())
			{
				auto prunlog = iLogS.value()->ConvertType<LoggerNS::IFileLogger*>();
				prunlog->LogFileMsgAsync(LoggerNS::ELogLevel::E_Error_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance()->GetMdlCnDesc(type) + "注册失败");
				prunlog->LogFileMsgAsync(LoggerNS::ELogLevel::E_Error_LV, exp.what());
				auto pstdoutlog = iLogS.value()->ConvertType<LoggerNS::IStdoutLogger*>();
				pstdoutlog->LogStdoutMsgAsync(LoggerNS::ELogLevel::E_Error_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance()->GetMdlCnDesc(type) + "注册失败");
				pstdoutlog->LogStdoutMsgAsync(LoggerNS::ELogLevel::E_Error_LV, exp.what());
			}
			//无论日志是否打印，均需要返回false
			return false;//初始化异常
		}
	}
}