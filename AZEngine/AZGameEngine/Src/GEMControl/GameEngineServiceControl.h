#pragma once
#include "CMNInterface/IMdlService.h"

namespace AZGameEngineNS
{
	/// <summary>
	/// 游戏引擎的业务逻辑控制器
	/// </summary>
	class GameEngineServiceControl :public MdlCommonNS::IMdlService
	{
	public:
		GameEngineServiceControl();
		~GameEngineServiceControl();
	};

}

