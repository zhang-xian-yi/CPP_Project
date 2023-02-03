#include "LoggerFactory.h"
#include "LMControl/LModuleControl.h"
#include "LMControl/LoggerControl.h"
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"

namespace LoggerNS
{
	/// <summary>
	/// 构件一个新业务控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* LoggerFactory::CreateServiceInstance()
	{
		return new LoggerNS::LoggerControl();
	}
	/// <summary>
	/// 构件一个新模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* LoggerFactory::CreateModuleInstance()
	{
		return new LoggerNS::LModuleControl();
	}
}