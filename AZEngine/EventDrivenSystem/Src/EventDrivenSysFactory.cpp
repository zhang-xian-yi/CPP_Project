#include "EventDrivenSysFactory.h"
#include "SEDMControl/EventDrivenSysMdlControl.h"
#include "SEDMControl/EventDrivenSysServiceControl.h"
namespace EventDrivenSysNS
{
	/// <summary>
	/// 业务实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* EventDrivenSysFactory::CreateServiceInstance()
	{
		return new EventDrivenSysNS::EventDrivenSysServiceControl();
	}
	/// <summary>
	/// 模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* EventDrivenSysFactory::CreateModuleInstance()
	{
		return new EventDrivenSysNS::EventDrivenSysMdlControl();
	}

}