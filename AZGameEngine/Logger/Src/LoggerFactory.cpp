#include "LoggerFactory.h"
#include "ILModule.h"
#include "ILogger.h"

namespace Log4CppNS
{
	ILogger* LoggerFactory::GetLoggerInstance()
	{
		return nullptr;
	}
	ILModule* LoggerFactory::GetModuleInstance()
	{
		return nullptr;
	}
}