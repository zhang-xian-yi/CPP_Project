#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"

namespace AZDataComputeNS
{
	/// <summary>
	/// 游戏引擎的业务逻辑控制器
	/// </summary>
	class DataComputeServiceControl :public MdlCommonNS::IMdlService
	{
	public:
		DataComputeServiceControl();
		~DataComputeServiceControl();
	};

}

