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

	bool GameEngineMdlControl::ConstructModule()
	{


		return true;
	}

	bool GameEngineMdlControl::DestoryModule()
	{


		return true;
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


