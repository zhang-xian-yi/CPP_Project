#include "StopAndUnRegisterAllService.h"
#include "CMNInterface/IMdlOperat.h"//模块操作接口
#include "CMNInterface/IMdlFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"//默认请求和响应
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "CMNMEnum/ModuelType/EModuleType.h"//模块类型
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