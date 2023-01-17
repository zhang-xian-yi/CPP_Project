#pragma once
#include "GECommon/ExpMarcoDefine.h"
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace AZGameEngineNS
{
	class GameEngineFactory :public MdlCommonNS::IMdlFactory
	{
	public:
		static GameEngineFactory& GetFactory()
		{
			static GameEngineFactory instance;
			return instance;
		}
	public:
		virtual MdlCommonNS::IMdlService* GetServiceInstance() override;
		virtual MdlCommonNS::IMdlOperat* GetModuleInstance() override;
	private:
		//禁止反复定义工厂，禁止delelte 工厂对象
		GameEngineFactory();
		~GameEngineFactory();
		GameEngineFactory(GameEngineFactory& instance) = delete;
		GameEngineFactory& operator=(const GameEngineFactory& instance) = delete;
	private:
		MdlCommonNS::IMdlService* m_pService;
		MdlCommonNS::IMdlOperat* m_pModule;
	};
}


