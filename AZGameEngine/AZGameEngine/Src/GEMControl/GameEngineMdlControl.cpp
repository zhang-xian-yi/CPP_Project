#include "GameEngineMdlControl.h"

namespace AZGameEngineNS
{
	GameEngineMdlControl::GameEngineMdlControl()
		:m_bIsUse(false)
	{
	}
	GameEngineMdlControl::~GameEngineMdlControl()
	{
	}

	MdlCommonNS::ISysResponse* GameEngineMdlControl::ConstructModule(const MdlCommonNS::ISysRequest* para)
	{
		return nullptr;
	}
	MdlCommonNS::ISysResponse* GameEngineMdlControl::DestoryModule(const MdlCommonNS::ISysRequest* para)
	{
		return nullptr;
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


