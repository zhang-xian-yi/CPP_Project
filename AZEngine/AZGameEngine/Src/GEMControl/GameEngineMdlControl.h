#pragma once
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"

namespace AZGameEngineNS
{
	//游戏引擎的模块控制器
	class GameEngineMdlControl :public MdlCommonNS::IMdlOperat
	{
	public:
		GameEngineMdlControl();
		~GameEngineMdlControl();
	public:
		//构造模块
		virtual bool ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
		//销毁模块
		virtual bool DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
		//获取模块状态
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//模块是否可用
	};
}


