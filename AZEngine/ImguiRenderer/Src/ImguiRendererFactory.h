#pragma once
#include "ImguiRenderer/Src/IRCommon/IRExpMarcoDefine.h"
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"

namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace ImguiRendererNS
{
	//imgui ����Ⱦ��
	class ImguiRendererFactory:MdlCommonNS::IMdlFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonFactory(ImguiRendererFactory)
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}


