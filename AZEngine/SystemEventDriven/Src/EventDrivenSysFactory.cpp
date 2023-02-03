#include "EventDrivenSysFactory.h"
#include "SEDMControl/SysEventDrivenMdlControl.h"
#include "SEDMControl/SysEventDrivenServiceControl.h"
namespace SysEventDNS
{
	/// <summary>
	/// ҵ��ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* EventDrivenSysFactory::CreateServiceInstance()
	{
		return new SysEventDNS::SysEventDrivenServiceControl();
	}
	/// <summary>
	/// ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* EventDrivenSysFactory::CreateModuleInstance()
	{
		return new SysEventDNS::SysEventDrivenMdlControl();
	}

}