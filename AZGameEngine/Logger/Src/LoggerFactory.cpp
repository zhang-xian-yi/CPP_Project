#include "LoggerFactory.h"
#include "Interface/IMdlOperat.h"
#include "Interface/IMdlService.h"
#include "MControl/LModuleControl.h"
#include "MControl/LoggerControl.h"
namespace Log4CppNS
{
	LoggerFactory::LoggerFactory()
		:m_pLog(nullptr),m_pModule(nullptr)
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

	CommonNS::IMdlService* LoggerFactory::GetLoggerInstance()
	{
		if (m_pLog == nullptr)
		{
			//初始化日志 
			m_pLog = new Log4CppNS::LoggerControl();
		}
		return m_pLog;
	}
	CommonNS::IMdlOperat* LoggerFactory::GetModuleInstance()
	{
		if (m_pModule == nullptr)
		{
			//初始化日志
			m_pModule = new Log4CppNS::LModuleControl();
		}
		return m_pModule;
	}
}