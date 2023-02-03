#include "DataComputeMdlControl.h"

namespace AZDataComputeNS
{
	DataComputeMdlControl::DataComputeMdlControl()
		:m_bIsUse(false)
	{
	}
	DataComputeMdlControl::~DataComputeMdlControl()
	{
	}

	bool DataComputeMdlControl::ConstructModule()
	{


		return true;
	}

	bool DataComputeMdlControl::DestoryModule()
	{


		return true;
	}



	/// <summary>
	/// 返回游戏引擎模块的状态
	/// </summary>
	/// <returns></returns>
	bool DataComputeMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}


