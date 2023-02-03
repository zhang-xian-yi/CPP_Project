#include "StopAndUnRegisterAllService.h"
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"//模块操作接口
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"//模块类型
namespace FuncScheduleNS
{
	/// <summary>
	/// 业务逻辑接口
	/// </summary>
	void StopAndUnRegisterAllService::DoService()
	{
		MdlCommonNS::ServiceContainerSingle::GetContainer().DestoryContaineer();
	}
}