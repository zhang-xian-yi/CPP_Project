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
	/// ������Ϸ����ģ���״̬
	/// </summary>
	/// <returns></returns>
	bool DataComputeMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}


