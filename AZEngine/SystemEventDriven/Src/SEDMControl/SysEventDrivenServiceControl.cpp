#include "SysEventDrivenServiceControl.h"

namespace SysEventDNS
{
	SysEventDrivenServiceControl::SysEventDrivenServiceControl()
	{
	}

	SysEventDrivenServiceControl::~SysEventDrivenServiceControl()
	{
	}

	bool SysEventDrivenServiceControl::Connect(ESysEventId eId, std::function<bool(IEvent*)> handler)
	{
		return false;
	}


	void SysEventDrivenServiceControl::DispatchEvent(IEvent* eve)
	{
		ESysEventId id = eve->GetEventId();
		
	}

	

}

