#include "SysEventDrivenFactory.h"
#include "SEDMControl/SysEventDrivenMdlControl.h"
#include "SEDMControl/SysEventDrivenServiceControl.h"
namespace SysEventDNS
{
	/// <summary>
	/// ҵ��ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* SysEventDrivenFactory::CreateServiceInstance()
	{
		return new SysEventDNS::SysEventDrivenServiceControl();
	}
	/// <summary>
	/// ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* SysEventDrivenFactory::CreateModuleInstance()
	{
		return new SysEventDNS::SysEventDrivenMdlControl();
	}

}