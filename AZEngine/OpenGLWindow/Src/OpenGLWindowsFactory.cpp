/********************************************************************************************
File Name		    :	AZWindowsFactory.cpp
File Path			:   G:\ProjectSrcDIr\Vs2019ProjectSrcDIr\CPP_Project\AZGameEngine\OpenGLUI\Src
File Declaration	:	
Modification Record :
---------------------------------------------------------------------------------------------
Author			Version			Date		
张贤忆			1.0				2023/01/29    
********************************************************************************************/
#include "OpenGLWindowsFactory.h"
#include "WMControl/WindowsMdlControl.h"
#include "WMControl/WindowsServiceControl.h"

namespace WindowsNS
{
	/// <summary>
	/// 创建一个模块业务实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* OpenGLWindowsFactory::CreateServiceInstance()
	{
		return new AZWindowsServiceControl();
	}

	/// <summary>
	/// 创建一个新的模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* OpenGLWindowsFactory::CreateModuleInstance()
	{
		return new AZWindowsMdlControl();
	}
}