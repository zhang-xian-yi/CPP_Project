#include "StdoutLogger.h"
#include <iostream>
#include "spdlog/logger.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace LoggerNS
{ 
	void StdoutLogger::AutoGenerateOutTarget()
	{

	}

	void StdoutLogger::CreateLogger()
	{
		try
		{
			m_pLogger = spdlog::stdout_color_mt("console");
			m_pLogger->set_pattern("[%Y:%m:%d %H:%M:%S] %^[%l]%$ >>> %v");
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			std::cout << "Create console logger failed: " << ex.what() << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}