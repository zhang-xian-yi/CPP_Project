#include "EventDrivenSysFactory.h"
#include "SEDMControl/SysEventDrivenMdlControl.h"
#include "SEDMControl/SysEventDrivenServiceControl.h"
namespace SysEventDNS
{
	/// <summary>
	/// 业务实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* EventDrivenSysFactory::CreateServiceInstance()
	{
		return new SysEventDNS::SysEventDrivenServiceControl();
	}
	/// <summary>
	/// 模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* EventDrivenSysFactory::CreateModuleInstance()
	{
		return new SysEventDNS::SysEventDrivenMdlControl();
	}

}