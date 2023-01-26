#include "GameEngineMdlControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

namespace AZGameEngineNS
{
	GameEngineMdlControl::GameEngineMdlControl()
		:m_bIsUse(false)
	{
	}
	GameEngineMdlControl::~GameEngineMdlControl()
	{
	}

	MdlCommonNS::ISysResponse* GameEngineMdlControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return pResult;
	}

	MdlCommonNS::ISysResponse* GameEngineMdlControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return pResult;
	}



	/// <summary>
	/// 返回游戏引擎模块的状态
	/// </summary>
	/// <returns></returns>
	bool GameEngineMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}


