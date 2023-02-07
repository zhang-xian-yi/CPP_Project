#include "StopAndUnRegisterAllService.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"//模块类型
namespace FuncScheduleNS
{
	/// <summary>
	/// 业务逻辑接口
	/// </summary>
	void StopAndUnRegisterAllService::DoService()
	{
		MdlCommonNS::ServiceContainerSingle::GetInstance().DestoryContaineer();
	}
}