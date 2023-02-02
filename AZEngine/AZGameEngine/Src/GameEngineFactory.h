#pragma once
#include "GECommon/ExpMarcoDefine.h"
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace AZGameEngineNS
{
	class GameEngineDLLAPI GameEngineFactory :public MdlCommonNS::IMdlFactory
	{
		//禁止反复定义工厂，禁止delelte 工厂对象
		SingletonFactory(GameEngineFactory)
	public:
		virtual MdlCommonNS::IMdlService* CreateServiceInstance() override;
		virtual MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}


