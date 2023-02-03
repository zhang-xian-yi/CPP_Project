#include "AZWindowsMdlControl.h"
namespace AZWindowsNS
{
	AZWindowsMdlControl::AZWindowsMdlControl()
		:m_bIsUse(false)
	{
	}
	AZWindowsMdlControl::~AZWindowsMdlControl()
	{
	}

	/// <summary>
	/// 构造模块
	/// </summary>
	/// <returns></returns>
	bool AZWindowsMdlControl::ConstructModule()
	{


		return true;
	}

	/// <summary>
	/// 销毁模块
	/// </summary>
	/// <returns></returns>
	bool AZWindowsMdlControl::DestoryModule()
	{


		return true;
	}

	//获取模块状态
	bool AZWindowsMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}