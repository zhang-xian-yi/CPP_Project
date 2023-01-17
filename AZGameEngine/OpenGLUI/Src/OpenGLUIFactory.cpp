#include "OpenGLUIFactory.h"
#include <OGMControl/OpenGLUIMdlControl.h>
#include <OGMControl/OpenGLUIServiceControl.h>

namespace OpenGLUINS
{
	OpenGLUIFactory::OpenGLUIFactory()
	{
	}
	OpenGLUIFactory::~OpenGLUIFactory()
	{
	}

	/// <summary>
	/// 创建一个新的业务控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* OpenGLUIFactory::CreateServiceInstance()
	{
		return new OpenGLUIServiceControl;
	}

	/// <summary>
	/// 创建一个新的模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* OpenGLUIFactory::CreateModuleInstance()
	{
		return new OpenGLUIMdlControl();
	}


}