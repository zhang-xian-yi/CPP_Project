#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"

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
	public:
		virtual std::unique_ptr<MdlCommonNS::ISysResponse> DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para = nullptr) override;
	};

}

