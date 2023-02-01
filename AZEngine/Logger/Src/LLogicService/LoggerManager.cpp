#include "LoggerManager.h"
#include "LoggerImpl/FileLogger.h"
#include "LoggerImpl/StdoutLogger.h"
#include "CMNServices/Utils/PathUtil.h"//路径获取
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
	/// 获取日志文件记录器
	/// </summary>
	/// <returns></returns>
	std::shared_ptr<spdlog::logger> LoggerManager::GetFileLogger()
	{
		return m_pFileLog->GetLogger();
	}
	/// <summary>
	/// 获取日志标准输出记录器
	/// </summary>
	/// <returns></returns>
	std::shared_ptr<spdlog::logger> LoggerManager::GetStdoutLogger()
	{
		return m_pStdoutLog->GetLogger();
	}
	/// <summary>
	/// 销毁日志
	/// </summary>
	void LoggerManager::Destory()
	{
		m_pFileLog->DestroyLogger();
		m_pStdoutLog->DestroyLogger();
	}
	/// <summary>
	/// 初始化日志
	/// </summary>
	void LoggerManager::Init()
	{
		spdlog::set_level(LOG_LEVEL_DEBUG);
		std::string path= MdlCommonNS::PathUtil::GetExecutePath() + "/Logs/";
		//文件日志
		m_pFileLog = new FileLogger(path);
		m_pFileLog->AutoGenerateOutTarget();
		m_pFileLog->CreateLogger();
		m_pFileLog->SetPrintLevel(LOG_LEVEL_DEBUG);
		//标准输出日志
		m_pStdoutLog = new StdoutLogger();
		m_pStdoutLog->CreateLogger();
		m_pStdoutLog->SetPrintLevel(LOG_LEVEL_DEBUG);
	}
}