#include "SysEventDrivenMdlControl.h"

namespace SysEventDNS
{
	SysEventDrivenMdlControl::SysEventDrivenMdlControl()
		:m_bIsUse(false)
	{
	}
	SysEventDrivenMdlControl::~SysEventDrivenMdlControl()
	{
	}

	bool SysEventDrivenMdlControl::ConstructModule()
	{


		return true;
	}

	bool SysEventDrivenMdlControl::DestoryModule()
	{


		return true;
	}



	/// <summary>
	/// 返回游戏引擎模块的状态
	/// </summary>
	/// <returns></returns>
	bool SysEventDrivenMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}


