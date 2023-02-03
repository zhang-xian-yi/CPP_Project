#pragma once
#include <WCommon/WExpMarcoDefine.h>
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace AZWindowsNS
{
	/// <summary>
	/// openGui ��ģ�鹤��
	/// </summary>
	class WindowsNSDLLAPI AZWindowsFactory :public MdlCommonNS::IMdlFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonFactory(AZWindowsFactory)
	public:
			
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}



