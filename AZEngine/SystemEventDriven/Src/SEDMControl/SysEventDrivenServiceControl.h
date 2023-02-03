#pragma once
#include "CMNInterface/IMdlService.h"

namespace SysEventDNS
{
	/// <summary>
	/// 游戏引擎的业务逻辑控制器
	/// </summary>
	class SysEventDrivenServiceControl :public MdlCommonNS::IMdlService
	{
	public:
		SysEventDrivenServiceControl();
		~SysEventDrivenServiceControl();
	};

}

