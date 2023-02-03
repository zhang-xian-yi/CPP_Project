#pragma once
#include "LCommon/LExpMarcoDefine.h"
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace LoggerNS
{
	//��־ģ��Ĺ���
	class LogerDLLAPI LoggerFactory :public MdlCommonNS::IMdlFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonFactory(LoggerFactory)
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}


