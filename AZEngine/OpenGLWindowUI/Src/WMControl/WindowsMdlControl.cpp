#include "WindowsMdlControl.h"
namespace WindowsNS
{
	WindowsMdlControl::WindowsMdlControl()
		:m_bIsUse(false)
	{
	}
	WindowsMdlControl::~WindowsMdlControl()
	{
	}

	/// <summary>
	/// 构造模块
	/// </summary>
	/// <returns></returns>
	bool WindowsMdlControl::ConstructModule()
	{


		return true;
	}

	/// <summary>
	/// 销毁模块
	/// </summary>
	/// <returns></returns>
	bool WindowsMdlControl::DestoryModule()
	{


		return true;
	}

	//获取模块状态
	bool WindowsMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}