#pragma once
#include "ImguiRenderer/Src/IRCommon/IRExpMarcoDefine.h"
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"

namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace ImguiRendererNS
{
	//imgui 的渲染器
	class ImguiRendererFactory:MdlCommonNS::IMdlFactory
	{
		//禁止反复定义工厂，禁止delelte 工厂对象
		SingletonFactory(ImguiRendererFactory)
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}


