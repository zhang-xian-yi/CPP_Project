#pragma once
#include "WCommon/WExpMarcoDef.h"
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace WindowsNS
{
	/// <summary>
	/// openGui 的模块工厂
	/// </summary>
	class WindowsNSDLLAPI OpenGLWindowsFactory :public MdlCommonNS::IMdlFactory
	{
		//禁止反复定义工厂，禁止delelte 工厂对象
		SingletonFactory(OpenGLWindowsFactory)
	public:
			
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}



