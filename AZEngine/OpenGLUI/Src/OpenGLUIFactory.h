#pragma once
#include <OGCommon/OGExpMarcoDefine.h>
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace OpenGLUINS
{
	/// <summary>
	/// openGui 的模块工厂
	/// </summary>
	class OpenGLUIAPI OpenGLUIFactory :public MdlCommonNS::IMdlFactory
	{
		//禁止反复定义工厂，禁止delelte 工厂对象
		SingletonFactory(OpenGLUIFactory)
	public:
			
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}



