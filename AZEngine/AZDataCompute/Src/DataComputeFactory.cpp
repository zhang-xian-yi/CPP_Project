#include "DataComputeFactory.h"
#include <DCMControl/DataComputeMdlControl.h>
#include <DCMControl/DataComputeServiceControl.h>

namespace AZDataComputeNS
{
	/// <summary>
	/// ����һ���µ�ҵ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* DataComputeFactory::CreateServiceInstance()
	{
		return new DataComputeServiceControl();
	}

	/// <summary>
	/// ����һ���µ�ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* DataComputeFactory::CreateModuleInstance()
	{
		return new DataComputeMdlControl();
	}
}
