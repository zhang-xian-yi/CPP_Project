#include "EventDrivenSysMdlControl.h"

namespace EventDrivenSysNS
{
	EventDrivenSysMdlControl::EventDrivenSysMdlControl()
		:m_bIsUse(false)
	{
	}
	EventDrivenSysMdlControl::~EventDrivenSysMdlControl()
	{
	}

	bool EventDrivenSysMdlControl::ConstructModule()
	{


		return true;
	}

	bool EventDrivenSysMdlControl::DestoryModule()
	{


		return true;
	}



	/// <summary>
	/// ������Ϸ����ģ���״̬
	/// </summary>
	/// <returns></returns>
	bool EventDrivenSysMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}


