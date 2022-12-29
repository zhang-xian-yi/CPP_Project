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
			//������־
			delete m_pLog;
			m_pLog = nullptr;
		}
		if (m_pModule != nullptr)
		{
			//������־
			delete m_pModule;
			m_pModule = nullptr;
		}
	}

	ILogger* LoggerFactory::GetLoggerInstance()
	{
		if (m_pLog == nullptr)
		{
			//��ʼ����־
			m_pLog = new Log4CppNS::LoggerControl();
		}
		return m_pLog;
	}
	ILModule* LoggerFactory::GetModuleInstance()
	{
		if (m_pModule == nullptr)
		{
			//��ʼ����־
			m_pModule = new Log4CppNS::LModuleControl();
		}
		return m_pModule;
	}
}