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
	/// ������Ϸ����ģ���״̬
	/// </summary>
	/// <returns></returns>
	bool SysEventDrivenMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}


