#include "LoggerFactory.h"
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/IMdlService.h"
#include "LMControl/LModuleControl.h"
#include "LMControl/LoggerControl.h"
namespace Log4CppNS
{
	LoggerFactory::LoggerFactory()
	{
	}

	LoggerFactory::~LoggerFactory()
	{

	}
	/// <summary>
	/// 构件一个新业务控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* LoggerFactory::CreateServiceInstance()
	{
		return new Log4CppNS::LoggerControl();
	}
	/// <summary>
	/// 构件一个新模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* LoggerFactory::CreateModuleInstance()
	{
		return new Log4CppNS::LModuleControl();
	}
}