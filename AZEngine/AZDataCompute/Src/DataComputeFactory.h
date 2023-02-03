#pragma once
#include "DCCommon/ExpMarcoDefine.h"
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace AZDataComputeNS
{
	class DataComputeNSDLLAPI DataComputeFactory :public MdlCommonNS::IMdlFactory
	{
		//禁止反复定义工厂，禁止delelte 工厂对象
		SingletonFactory(DataComputeFactory)
	public:
		virtual MdlCommonNS::IMdlService* CreateServiceInstance() override;
		virtual MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}


