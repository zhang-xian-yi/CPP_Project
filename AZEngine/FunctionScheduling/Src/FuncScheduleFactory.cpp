#include "FuncScheduleFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/IMdlOperat.h"
//实现类
#include <FSMControl/FuncMdlControl.h>
#include <FSMControl/FuncScheduleControl.h>
namespace FuncScheduleNS
{
	/// <summary>
	/// 创建一个新的业务控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* FuncScheduleFactory::CreateServiceInstance()
	{
		return new FuncScheduleNS::FuncScheduleControl();
	}

	/// <summary>
	/// 创建一个新的模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* FuncScheduleFactory::CreateModuleInstance()
	{
		return new FuncScheduleNS::FuncMdlControl();
	}
}