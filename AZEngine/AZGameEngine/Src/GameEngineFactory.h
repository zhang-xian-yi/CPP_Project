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
	public:
		static MdlCommonNS::IMdlFactory* GetFactory()
		{
			static GameEngineFactory instance;
			return &instance;
		}
	public:
		virtual MdlCommonNS::IMdlService* CreateServiceInstance() override;
		virtual MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	private:
		//��ֹ�������幤������ֹdelelte ��������
		GameEngineFactory();
		~GameEngineFactory();
		GameEngineFactory(GameEngineFactory& instance) = delete;
		GameEngineFactory& operator=(const GameEngineFactory& instance) = delete;
	};
}


