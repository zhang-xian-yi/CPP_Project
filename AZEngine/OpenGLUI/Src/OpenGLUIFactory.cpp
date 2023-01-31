/********************************************************************************************
File Name		    :	OpenGLUIFactory.cpp
File Path			:   G:\ProjectSrcDIr\Vs2019ProjectSrcDIr\CPP_Project\AZGameEngine\OpenGLUI\Src
File Declaration	:	
Modification Record :
---------------------------------------------------------------------------------------------
Author			Version			Date		
张贤忆			1.0				2023/01/29    
********************************************************************************************/
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