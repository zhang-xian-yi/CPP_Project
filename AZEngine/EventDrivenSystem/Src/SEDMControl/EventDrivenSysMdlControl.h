#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"

namespace EventDrivenSysNS
{
	//游戏引擎的模块控制器
	class EventDrivenSysMdlControl :public MdlCommonNS::IMdlOperat
	{
	public:
		EventDrivenSysMdlControl();
		~EventDrivenSysMdlControl();
	public:
		//构造模块
		virtual bool ConstructModule() override;
		//销毁模块
		virtual bool DestoryModule() override;
		//获取模块状态
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//模块是否可用
	};
}


