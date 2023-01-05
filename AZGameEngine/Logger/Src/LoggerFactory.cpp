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

	CommonNS::IMdlService* LoggerFactory::GetLoggerInstance()
	{
		if (m_pLog == nullptr)
		{
			//��ʼ����־ 
			m_pLog = new Log4CppNS::LoggerControl();
		}
		return m_pLog;
	}
	CommonNS::IMdlOperat* LoggerFactory::GetModuleInstance()
	{
		if (m_pModule == nullptr)
		{
			//��ʼ����־
			m_pModule = new Log4CppNS::LModuleControl();
		}
		return m_pModule;
	}
}