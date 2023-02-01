#include "LoggerManager.h"
#include "LoggerImpl/FileLogger.h"
#include "LoggerImpl/StdoutLogger.h"
#include "CMNServices/Utils/PathUtil.h"//·����ȡ
namespace LoggerNS
{
	LoggerManager::LoggerManager()
	{
		Init();
	}
	LoggerManager::~LoggerManager()
	{
		Destory();
		if (m_pFileLog)
		{
			delete m_pFileLog;
			m_pFileLog = nullptr;
		}
		if (m_pStdoutLog)
		{
			delete m_pStdoutLog;
			m_pStdoutLog = nullptr;
		}
	}
	/// <summary>
	/// ��ȡ��־�ļ���¼��
	/// </summary>
	/// <returns></returns>
	std::shared_ptr<spdlog::logger> LoggerManager::GetFileLogger()
	{
		return m_pFileLog->GetLogger();
	}
	/// <summary>
	/// ��ȡ��־��׼�����¼��
	/// </summary>
	/// <returns></returns>
	std::shared_ptr<spdlog::logger> LoggerManager::GetStdoutLogger()
	{
		return m_pStdoutLog->GetLogger();
	}
	/// <summary>
	/// ������־
	/// </summary>
	void LoggerManager::Destory()
	{
		m_pFileLog->DestroyLogger();
		m_pStdoutLog->DestroyLogger();
	}
	/// <summary>
	/// ��ʼ����־
	/// </summary>
	void LoggerManager::Init()
	{
		spdlog::set_level(LOG_LEVEL_DEBUG);
		std::string path= MdlCommonNS::PathUtil::GetExecutePath() + "/Logs/";
		//�ļ���־
		m_pFileLog = new FileLogger(path);
		m_pFileLog->AutoGenerateOutTarget();
		m_pFileLog->CreateLogger();
		m_pFileLog->SetPrintLevel(LOG_LEVEL_DEBUG);
		//��׼�����־
		m_pStdoutLog = new StdoutLogger();
		m_pStdoutLog->CreateLogger();
		m_pStdoutLog->SetPrintLevel(LOG_LEVEL_DEBUG);
	}
}