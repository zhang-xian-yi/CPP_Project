#pragma once
#include "DCCommon/ExpMarcoDefine.h"
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace AZDataComputeNS
{
	class DataComputeNSDLLAPI DataComputeFactory :public MdlCommonNS::IMdlFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonFactory(DataComputeFactory)
	public:
		virtual MdlCommonNS::IMdlService* CreateServiceInstance() override;
		virtual MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}


