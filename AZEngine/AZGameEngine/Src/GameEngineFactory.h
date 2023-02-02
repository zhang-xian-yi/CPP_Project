#pragma once
#include "GECommon/ExpMarcoDefine.h"
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace AZGameEngineNS
{
	class GameEngineDLLAPI GameEngineFactory :public MdlCommonNS::IMdlFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonFactory(GameEngineFactory)
	public:
		virtual MdlCommonNS::IMdlService* CreateServiceInstance() override;
		virtual MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}


