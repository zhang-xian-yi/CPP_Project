#include "FileLogger.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "CMNServices/Utils/DateTimeUtil.h"
namespace LoggerNS
{
	FileLogger::FileLogger(const std::string& str)
		:m_logPath(str)
	{

	}

	/// <summary>
	/// ����Ŀ���Ŀ¼
	/// </summary>
	void FileLogger::AutoGenerateOutTarget()
	{
		/* �ж���־·���Ƿ���ڣ��������ڣ��򴴽� */
		namespace fs = std::filesystem;
		if (!fs::exists(m_logPath))
		{
			fs::create_directory(m_logPath);
		}
	}

	/// <summary>
	/// ������־��¼
	/// </summary>
	void FileLogger::CreateLogger()
	{
		try
		{
			std::string localtime = MdlCommonNS::DateTimeUtil::GetDayTime();
			std::string logFileFullName = m_logPath + "//" + localtime + ".log";
			m_pLogger = spdlog::rotating_logger_mt("basic_logger", logFileFullName, 1024 * 1024 * 3, spdlog::level::debug);
			m_pLogger->set_pattern("[%Y:%m:%d %H:%M:%S] %^[%l]%$ >>> %v");
			m_pLogger->set_level(spdlog::level::trace);
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			//std::cout << "Create file logger failed: " << ex.what() << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}