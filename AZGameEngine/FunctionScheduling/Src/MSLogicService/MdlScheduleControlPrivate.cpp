#include "MdlScheduleControlPrivate.h"
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/IMdlFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNServices/ServiceContainerSingle.h"//业务容器
#include "CMNMEnum/ModuelType/EModuleType.h"//模块类型
#include "LoggerFactory.h"//日志工厂类
#include "MdlScheduleFactory.h"//模块调度工厂类
#include "OpenGLUIFactory.h"//OPenglUI的工厂类
#include "GameEngineFactory.h"//游戏引擎工厂类
using namespace MdlCommonNS;

namespace MdlScheduleNS
{
	/// <summary>
	/// 初始化/注册 所有的功能模块
	/// </summary>
	void MdlScheduleControlPrivate::InitAndRegisterAllService()
	{
		IMdlFactory* pFactory = nullptr;
		//初始化/注册模块调度实例
		pFactory = MdlScheduleNS::MdlScheduleFactory::GetFactory();
		InitAndRegisterService(EModuleType::E_FuncSchedule_Type, pFactory);
		//初始化/注册日志实例
		pFactory = Log4CppNS::LoggerFactory::GetFactory();
		InitAndRegisterService(EModuleType::E_Logger_Type, pFactory);
		//初始化/注册游戏引擎实例
		pFactory = AZGameEngineNS::GameEngineFactory::GetFactory();
		InitAndRegisterService(EModuleType::E_GameEngine_Type, pFactory);
		//初始化/注册OpenglUI实例
		pFactory = OpenGLUINS::OpenGLUIFactory::GetFactory();
		InitAndRegisterService(EModuleType::E_OpengGLUI_Type, pFactory);

		
	}

	/// <summary>
	/// 将指定类型的工厂指针创建的模块控制对象和业务逻辑控制对象注册进入服务容器
	/// </summary>
	/// <param name="type">模块类型</param>
	/// <param name="factory">对应模块的开发工厂指针</param>
	void MdlScheduleControlPrivate::InitAndRegisterService(EModuleType type,IMdlFactory* factory)
	{
		//注意此处构建的是new 对象， 需要添加智能指针进行管理
		MdlCommonNS::IMdlOperat* pMdl = factory->CreateModuleInstance();
		MdlCommonNS::IMdlService* pService = factory->CreateServiceInstance();
		//初始化模块
		pMdl->ConstructModule();
		//注册模块
		ServiceContainerSingle::GetContainer().RegisterModuleInterface(type, pMdl, pService);
	}
}

