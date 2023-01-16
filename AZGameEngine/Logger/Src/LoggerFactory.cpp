#include "LoggerFactory.h"
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/IMdlService.h"
#include "LMControl/LModuleControl.h"
#include "LMControl/LoggerControl.h"
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

	MdlCommonNS::IMdlService* LoggerFactory::GetLoggerInstance()
	{
		if (m_pLog == nullptr)
		{
			//��ʼ����־ 
			m_pLog = new Log4CppNS::LoggerControl();
		}
		return m_pLog;
	}
	MdlCommonNS::IMdlOperat* LoggerFactory::GetModuleInstance()
	{
		if (m_pModule == nullptr)
		{
			//��ʼ����־
			m_pModule = new Log4CppNS::LModuleControl();
		}
		return m_pModule;
	}
}