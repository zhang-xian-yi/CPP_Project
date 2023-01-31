#include "LoggerManager.h"
#include "spdlog/cfg/env.h"  // support for loading levels from the environment  variable
#include "spdlog/fmt/ostr.h" // support for user defined types
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace LoggerNS
{
	LoggerManager::LoggerManager()
	{
		init();
	}
	LoggerManager::~LoggerManager()
	{
	}
	std::shared_ptr<spdlog::logger> LoggerManager::GetOperatLogger()
	{
		return m_pOptLog;
	}
	std::shared_ptr<spdlog::logger> LoggerManager::GetRunLogger()
	{
		return m_pRunLog;
	}
	std::shared_ptr<spdlog::logger> LoggerManager::GetConsoleLogger()
	{
		return m_pStdoutLog;
	}
	/// <summary>
	/// ��ʼ����־
	/// </summary>
	void LoggerManager::init()
	{
		spdlog::set_level(spdlog::level::debug);

		InitOptLogger("OptLogger","Logs/OptLog.txt",1024 * 1024 * 3,spdlog::level::debug);
		InitRunLogger("RunLogger", "Logs/RunLog.txt", 1024 * 1024 * 3, spdlog::level::debug);
		InitStdoutLogger("StdoutLog");
	}

	/// <summary>
	/// ��ʼ�� ������־
	/// </summary>
	/// <param name="logName">��־����</param>
	/// <param name="logFile">��־�ļ�·��</param>
	/// <param name="max_file_size">�ļ�����С</param>
	/// <param name="level">��־�ȼ�</param>
	void LoggerManager::InitOptLogger(const std::string& logName, const std::string& logFile, size_t max_file_size, spdlog::level::level_enum level)
	{
		try
		{
			//������־�ļ������߸�
			m_pOptLog = spdlog::rotating_logger_mt(logName, logFile, max_file_size, 7);
			m_pOptLog->set_level(level);
			m_pOptLog->set_pattern("[%Y:%m:%d %H:%M:%S] [%l] [%n] >>> %v%$");
		}
		catch (std::exception e)
		{

		}
	}
	/// <summary>
	/// ��ʼ�� ������־
	/// </summary>
	/// <param name="logName">��־����</param>
	/// <param name="logFile">��־�ļ�·��</param>
	/// <param name="max_file_size">�ļ�����С</param>
	/// <param name="level">��־�ȼ�</param>
	void LoggerManager::InitRunLogger(const std::string& logName, const std::string& logFile, size_t max_file_size, spdlog::level::level_enum level)
	{
		try
		{
			//������־�ļ������߸�
			m_pRunLog = spdlog::rotating_logger_mt(logName, logFile, max_file_size, 7);
			m_pRunLog->set_level(level);
			m_pRunLog->set_pattern("[%Y:%m:%d %H:%M:%S] [%l] [%n] >>> %v%$");
		}
		catch (std::exception e)
		{

		}
	}
	/// <summary>
	/// ��ʼ�� ����̨��־
	/// </summary>
	/// <param name="logName">��־����</param>
	/// <param name="logFile">��־�ļ�·��</param>
	/// <param name="max_file_size">�ļ�����С</param>
	/// <param name="level">��־�ȼ�</param>
	void LoggerManager::InitStdoutLogger(const std::string& logName)
	{
		try
		{
			//���׼��������Ϣ
			m_pStdoutLog = spdlog::stdout_color_mt(logName);
			m_pStdoutLog->set_pattern("[%Y:%m:%d %H:%M:%S] [%l] [%n] >>> %v%$");
		}
		catch (std::exception e)
		{

		}
	}
}