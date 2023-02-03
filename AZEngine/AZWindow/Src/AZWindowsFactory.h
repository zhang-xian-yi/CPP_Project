#pragma once
#include <WCommon/WExpMarcoDefine.h>
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace AZWindowsNS
{
	/// <summary>
	/// openGui 的模块工厂
	/// </summary>
	class WindowsNSDLLAPI AZWindowsFactory :public MdlCommonNS::IMdlFactory
	{
		//禁止反复定义工厂，禁止delelte 工厂对象
		SingletonFactory(AZWindowsFactory)
	public:
			
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}



