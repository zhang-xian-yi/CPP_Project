#pragma once
#include "LCommon/LExpMarcoDefine.h"

namespace MdlCommonNS
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

		MdlCommonNS::IMdlService* GetLoggerInstance();
		MdlCommonNS::IMdlOperat* GetModuleInstance();
	private:
		MdlCommonNS::IMdlService* m_pLog;
		MdlCommonNS::IMdlOperat* m_pModule;
	};
}


