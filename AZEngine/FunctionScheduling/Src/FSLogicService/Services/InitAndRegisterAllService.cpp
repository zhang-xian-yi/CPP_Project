#include "InitAndRegisterAllService.h"
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
#include "ImguiRenderer/Src/ImguiRendererFactory.h"//Imgui Renderer 工厂类
namespace FuncScheduleNS
{
	using namespace MdlCommonNS;

	//静态方法
	static void LogInitMsg(EModuleType mdlType, std::future<bool>& result)
	{
		std::string mdlDesc = MdlCommonNS::EnumModuleTypeExtend::GetInstance().GetMdlCnDesc(mdlType);
		try
		{
			std::future_status m_status;
			do
			{
				//轮询等待异步执行
				m_status = result.wait_for(std::chrono::milliseconds(100));
				switch (m_status)
				{
				case std::future_status::ready:
					break;
				case std::future_status::timeout:
					
					break;
				case std::future_status::deferred:
					result.wait();
					break;
				default:
					break;
				}
			} while (m_status != std::future_status::ready);


			if (result.get())
			{
				std::string userMsg = mdlDesc + "注册成功";
				MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV, userMsg);
			}
			else
			{
				std::string userMsg = mdlDesc + "注册失败";
				MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV, userMsg);
			}
		}
		catch (std::exception& exp)
		{
			std::string userMsg = mdlDesc + "注册异常";
			std::string expMsg = exp.what();
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, userMsg);
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, expMsg);
		}
	}


	void InitAndRegisterAllService::DoService()
	{
		/*注意--模块越复杂与庞大的应该越先注册，如此时间约平均*/

		IMdlFactory* pFactory = nullptr;
		//初始化/注册窗口实例
		pFactory = WindowsNS::OpenGLWindowsFactory::GetFactory();
		std::future<bool> OWResult = InitAndRegisterMdlAsync(EModuleType::E_OpenGLWindow_Type, pFactory);
		//初始化/注册日志实例
		pFactory = LoggerNS::LoggerFactory::GetFactory();
		std::future<bool> logResult = InitAndRegisterMdlAsync(EModuleType::E_Logger_Type, pFactory);
		//同步 初始化/注册系统事件驱动实例
		pFactory = EventDrivenSysNS::EventDrivenSysFactory::GetFactory();
		std::future<bool> EDSResult = InitAndRegisterMdlAsync(EModuleType::E_EventDrivenSys_Type, pFactory);
		//初始化/注册数据计算实例
		pFactory = AZDataComputeNS::DataComputeFactory::GetFactory();
		std::future<bool> DCResult = InitAndRegisterMdlAsync(EModuleType::E_DataCompute_Type, pFactory);
		//初始化 imguiRenderLayer
		pFactory = ImguiRendererNS::ImguiRendererFactory::GetFactory();
		std::future<bool> IRResult = InitAndRegisterMdlAsync(EModuleType::E_ImguiRenderer_Type, pFactory);



		//打印日志 ImguiRendererNS
		LogInitMsg(EModuleType::E_Logger_Type, logResult);
		LogInitMsg(EModuleType::E_EventDrivenSys_Type, EDSResult);
		LogInitMsg(EModuleType::E_DataCompute_Type, DCResult);
		LogInitMsg(EModuleType::E_OpenGLWindow_Type, OWResult);
		LogInitMsg(EModuleType::E_ImguiRenderer_Type, IRResult);
	}
	/// <summary>
	/// 异步执行任务
	/// </summary>
	/// <param name="type"></param>
	/// <param name="factory"></param>
	std::future<bool> InitAndRegisterAllService::InitAndRegisterMdlAsync(MdlCommonNS::EModuleType type, MdlCommonNS::IMdlFactory* factory)
	{
		return std::async(&InitAndRegisterAllService::InitAndRegisterMdl, this, type, factory); // (2) async call 
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
			ServiceContainerSingle::GetInstance().RegisterModuleInterface(type, pMdl, pService);
			return rep;
		}
		catch (std::exception&)
		{
			//无论日志是否打印，均需要返回false
			return false;//初始化异常
		}
	}
}