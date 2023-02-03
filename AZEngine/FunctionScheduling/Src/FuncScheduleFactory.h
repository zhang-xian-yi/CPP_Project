#pragma once
#include "FSCommon/MSExpMarcoDefine.h"
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace FuncScheduleNS
{
	/// <summary>
	/// 功能调度模块的工厂
	/// </summary>
	class MdlScheduleDLLAPI FuncScheduleFactory:public MdlCommonNS::IMdlFactory
	{
		//禁止反复定义工厂，禁止delelte 工厂对象
		SingletonFactory(FuncScheduleFactory)
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}


