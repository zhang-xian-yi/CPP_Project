/********************************************************************************************
File Name		    :	OpenGLUIFactory.cpp
File Path			:   G:\ProjectSrcDIr\Vs2019ProjectSrcDIr\CPP_Project\AZGameEngine\OpenGLUI\Src
File Declaration	:	
Modification Record :
---------------------------------------------------------------------------------------------
Author			Version			Date		
������			1.0				2023/01/29    
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
	/// ����һ���µ�ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* OpenGLUIFactory::CreateModuleInstance()
	{
		return new OpenGLUIMdlControl();
	}


}