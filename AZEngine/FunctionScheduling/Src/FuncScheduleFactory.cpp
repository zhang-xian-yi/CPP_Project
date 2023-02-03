#include "FuncScheduleFactory.h"
//实现类
#include <FSMControl/FuncMdlControl.h>
#include <FSMControl/FuncScheduleControl.h>
//外部头文件
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"

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