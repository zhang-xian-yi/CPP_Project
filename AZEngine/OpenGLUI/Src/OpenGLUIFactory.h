#pragma once
#include <OGCommon/OGExpMarcoDefine.h>
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace OpenGLUINS
{
	/// <summary>
	/// openGui ��ģ�鹤��
	/// </summary>
	class OpenGLUIAPI OpenGLUIFactory :public MdlCommonNS::IMdlFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonFactory(OpenGLUIFactory)
	public:
			
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}



