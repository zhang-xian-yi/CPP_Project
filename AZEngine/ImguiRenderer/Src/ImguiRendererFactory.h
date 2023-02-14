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
	class ImguiRendererNSAPI ImguiRendererFactory:public MdlCommonNS::IMdlFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonFactory(ImguiRendererFactory)
	public:
		virtual MdlCommonNS::IMdlService* CreateServiceInstance() override;
		virtual MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}


