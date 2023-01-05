#pragma once
#include "Common/MarcoDefine.h"

namespace CommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace Log4CppNS
{
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

		CommonNS::IMdlService* GetLoggerInstance();
		CommonNS::IMdlOperat* GetModuleInstance();
	private:
		CommonNS::IMdlService* m_pLog;
		CommonNS::IMdlOperat* m_pModule;
	};
}


