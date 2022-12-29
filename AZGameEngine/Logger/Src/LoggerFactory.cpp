#include "LoggerFactory.h"
#include "ILModule.h"
#include "ILogger.h"
#include "MControl/LModuleControl.h"
#include "MControl/LoggerControl.h"
namespace Log4CppNS
{
	LoggerFactory::LoggerFactory()
	{
	}
	LoggerFactory::~LoggerFactory()
	{
		if (m_pLog != nullptr)
		{
			//销毁日志
			delete m_pLog;
			m_pLog = nullptr;
		}
		if (m_pModule != nullptr)
		{
			//销毁日志
			delete m_pModule;
			m_pModule = nullptr;
		}
	}

	ILogger* LoggerFactory::GetLoggerInstance()
	{
		if (m_pLog == nullptr)
		{
			//初始化日志
			m_pLog = new Log4CppNS::LoggerControl();
		}
		return m_pLog;
	}
	ILModule* LoggerFactory::GetModuleInstance()
	{
		if (m_pModule == nullptr)
		{
			//初始化日志
			m_pModule = new Log4CppNS::LModuleControl();
		}
		return m_pModule;
	}
}