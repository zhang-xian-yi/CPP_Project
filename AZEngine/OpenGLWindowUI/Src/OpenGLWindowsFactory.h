#pragma once
#include "WCommon/WExpMarcoDef.h"
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace WindowsNS
{
	/// <summary>
	/// openGui ��ģ�鹤��
	/// </summary>
	class WindowsNSDLLAPI OpenGLWindowsFactory :public MdlCommonNS::IMdlFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonFactory(OpenGLWindowsFactory)
	public:
			
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}



