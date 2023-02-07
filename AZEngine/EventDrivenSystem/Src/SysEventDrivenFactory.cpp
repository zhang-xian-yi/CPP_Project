#include "SysEventDrivenFactory.h"
#include "SEDMControl/SysEventDrivenMdlControl.h"
#include "SEDMControl/SysEventDrivenServiceControl.h"
namespace SysEventDNS
{
	/// <summary>
	/// 业务实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* SysEventDrivenFactory::CreateServiceInstance()
	{
		return new SysEventDNS::SysEventDrivenServiceControl();
	}
	/// <summary>
	/// 模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* SysEventDrivenFactory::CreateModuleInstance()
	{
		return new SysEventDNS::SysEventDrivenMdlControl();
	}

}