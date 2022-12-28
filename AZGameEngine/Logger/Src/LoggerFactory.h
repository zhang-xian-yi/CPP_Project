#pragma once
namespace Log4CppNS
{
	//前置声明
	class ILModule;
	class ILogger;

	//日志模块的工厂
	class LoggerFactory
	{
	public:
		ILogger* GetLoggerInstance();
		ILModule* GetModuleInstance();
	};
}


