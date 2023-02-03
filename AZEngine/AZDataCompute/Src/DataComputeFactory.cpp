#include "DataComputeFactory.h"
#include <DCMControl/DataComputeMdlControl.h>
#include <DCMControl/DataComputeServiceControl.h>

namespace AZDataComputeNS
{
	/// <summary>
	/// 创建一个新的业务控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* DataComputeFactory::CreateServiceInstance()
	{
		return new DataComputeServiceControl();
	}

	/// <summary>
	/// 创建一个新的模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* DataComputeFactory::CreateModuleInstance()
	{
		return new DataComputeMdlControl();
	}
}
