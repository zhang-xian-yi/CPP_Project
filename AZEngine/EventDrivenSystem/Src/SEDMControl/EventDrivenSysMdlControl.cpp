#include "EventDrivenSysMdlControl.h"

namespace EventDrivenSysNS
{
	EventDrivenSysMdlControl::EventDrivenSysMdlControl()
		:m_bIsUse(false)
	{
	}
	EventDrivenSysMdlControl::~EventDrivenSysMdlControl()
	{
	}

	bool EventDrivenSysMdlControl::ConstructModule()
	{


		return true;
	}

	bool EventDrivenSysMdlControl::DestoryModule()
	{


		return true;
	}



	/// <summary>
	/// 返回游戏引擎模块的状态
	/// </summary>
	/// <returns></returns>
	bool EventDrivenSysMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}


