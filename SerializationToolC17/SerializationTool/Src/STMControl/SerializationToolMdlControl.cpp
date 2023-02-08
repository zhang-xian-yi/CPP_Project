#include "SerializationToolMdlControl.h"

namespace SerializationToolNS
{
	SerializationToolMdlControl::SerializationToolMdlControl()
		:m_bIsUse(false)
	{
	}
	SerializationToolMdlControl::~SerializationToolMdlControl()
	{
	}

	bool SerializationToolMdlControl::ConstructModule()
	{


		return true;
	}

	bool SerializationToolMdlControl::DestoryModule()
	{


		return true;
	}



	/// <summary>
	/// 返回游戏引擎模块的状态
	/// </summary>
	/// <returns></returns>
	bool SerializationToolMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}


