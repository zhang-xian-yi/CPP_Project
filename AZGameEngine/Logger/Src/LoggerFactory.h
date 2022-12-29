#pragma once
#include "Common/MarcoDefine.h"

namespace Log4CppNS
{
	//前置声明
	class ILModule;
	class ILogger;

	//日志模块的工厂
	class LogerAPI LoggerFactory
	{
	public:
		static LoggerFactory& GetFactory()
		{
			static LoggerFactory instance;
			return instance;
		}
	public:
		LoggerFactory();
		~LoggerFactory();

		ILogger* GetLoggerInstance();
		ILModule* GetModuleInstance();
	private:
		ILogger* m_pLog;
		ILModule* m_pModule;
	};
}


