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
	/// ������Ϸ����ģ���״̬
	/// </summary>
	/// <returns></returns>
	bool SerializationToolMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}


