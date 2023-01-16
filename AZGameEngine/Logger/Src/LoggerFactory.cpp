#include "LoggerFactory.h"
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/IMdlService.h"
#include "LMControl/LModuleControl.h"
#include "LMControl/LoggerControl.h"
namespace Log4CppNS
{
	LoggerFactory::LoggerFactory()
		:m_pService(nullptr),m_pModule(nullptr)
	{
	}
	LoggerFactory::~LoggerFactory()
	{
		if (m_pService != nullptr)
		{
			//������־
			delete m_pService;
			m_pService = nullptr;
		}
		if (m_pModule != nullptr)
		{
			//������־
			delete m_pModule;
			m_pModule = nullptr;
		}
	}

	MdlCommonNS::IMdlService* LoggerFactory::GetServiceInstance()
	{
		if (m_pService == nullptr)
		{
			//��ʼ����־ 
			m_pService = new Log4CppNS::LoggerControl();
		}
		return m_pService;
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