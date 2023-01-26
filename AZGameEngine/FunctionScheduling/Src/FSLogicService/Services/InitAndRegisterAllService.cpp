#include "InitAndRegisterAllService.h"
#include <future>//异步执行头文件
#include <thread>
#include "CMNInterface/IMdlOperat.h"//模块操作接口
#include "CMNInterface/IMdlFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"//默认请求和响应
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNServices/ServiceContainerSingle.h"//业务容器
#include "CMNMEnum/ModuelType/EModuleType.h"//模块类型
#include "LoggerFactory.h"//日志工厂类
#include "FuncScheduleFactory.h"//模块调度工厂类
#include "OpenGLUIFactory.h"//OPenglUI的工厂类
#include "GameEngineFactory.h"//游戏引擎工厂类
namespace FuncScheduleNS
{
	using namespace MdlCommonNS;

	void InitAndRegisterAllService::DoService()
	{
		IMdlFactory* pFactory = nullptr;
		//初始化/注册模块调度实例
		pFactory = FuncScheduleNS::FuncScheduleFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_FuncSchedule_Type, pFactory);
		//初始化/注册日志实例
		pFactory = Log4CppNS::LoggerFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_Logger_Type, pFactory);
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
			pMdl->ConstructModule();
			//注册模块
			ServiceContainerSingle::GetContainer().RegisterModuleInterface(type, pMdl, pService);
			return true;
		}
		catch (std::exception exp)
		{
			auto iLogS = ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_Logger_Type);
			if (iLogS.has_value())
			{
				//构造参数
				auto pRequest = new MdlCommonNS::DefSysRequest();
				std::any data = std::make_any<std::exception>(exp);
				pRequest->SetData(data);
				//打印日志
				iLogS.value()->DoService(std::unique_ptr<MdlCommonNS::ISysRequest>(pRequest));
			}
			//无论日志是否打印，均需要返回false
			return false;//初始化异常
		}
	}
}