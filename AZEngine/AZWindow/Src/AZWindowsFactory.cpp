/********************************************************************************************
File Name		    :	AZWindowsFactory.cpp
File Path			:   G:\ProjectSrcDIr\Vs2019ProjectSrcDIr\CPP_Project\AZGameEngine\OpenGLUI\Src
File Declaration	:	
Modification Record :
---------------------------------------------------------------------------------------------
Author			Version			Date		
������			1.0				2023/01/29    
********************************************************************************************/
#include "AZWindowsFactory.h"
#include <WMControl/AZWindowsMdlControl.h>
#include <WMControl/AZWindowsServiceControl.h>

namespace AZWindowsNS
{
	/// <summary>
	/// ����һ��ģ��ҵ��ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* AZWindowsFactory::CreateServiceInstance()
	{
		return new AZWindowsServiceControl();
	}

	/// <summary>
	/// ����һ���µ�ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* AZWindowsFactory::CreateModuleInstance()
	{
		return new AZWindowsMdlControl();
	}
}