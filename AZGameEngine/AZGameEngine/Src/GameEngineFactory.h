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
		//��ֹ�������幤������ֹdelelte ��������
		GameEngineFactory();
		~GameEngineFactory();
		GameEngineFactory(GameEngineFactory& instance) = delete;
		GameEngineFactory& operator=(const GameEngineFactory& instance) = delete;
	private:
		MdlCommonNS::IMdlService* m_pService;
		MdlCommonNS::IMdlOperat* m_pModule;
	};
}


