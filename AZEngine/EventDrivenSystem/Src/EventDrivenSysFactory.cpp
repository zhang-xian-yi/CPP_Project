#include "EventDrivenSysFactory.h"
#include "SEDMControl/EventDrivenSysMdlControl.h"
#include "SEDMControl/EventDrivenSysServiceControl.h"
namespace EventDrivenSysNS
{
	/// <summary>
	/// ҵ��ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* EventDrivenSysFactory::CreateServiceInstance()
	{
		return new EventDrivenSysNS::EventDrivenSysServiceControl();
	}
	/// <summary>
	/// ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* EventDrivenSysFactory::CreateModuleInstance()
	{
		return new EventDrivenSysNS::EventDrivenSysMdlControl();
	}

}