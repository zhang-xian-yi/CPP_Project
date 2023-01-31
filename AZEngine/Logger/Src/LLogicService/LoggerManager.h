#pragma once
#include <memory>
#include <string>
#include "spdlog/spdlog.h"

namespace LoggerNS
{
	/// <summary>
	/// 输出到控制台的业务逻辑
	/// </summary>
	class LoggerManager
	{
	public:
		static LoggerManager* GetInstance()
		{
			static LoggerManager instance;
			return &instance;
		}

		std::shared_ptr<spdlog::logger> GetOperatLogger();
		std::shared_ptr<spdlog::logger> GetRunLogger();
		std::shared_ptr<spdlog::logger> GetConsoleLogger();
	private:
		void init();
		void InitOptLogger(const std::string& logName, const std::string& logFile,size_t max_file_size,spdlog::level::level_enum level);
		void InitRunLogger(const std::string& logName, const std::string& logFile, size_t max_file_size, spdlog::level::level_enum level);
		void InitStdoutLogger(const std::string& logName);
	private:
		//禁止反复定义工厂，禁止delelte 工厂对象
		LoggerManager();
		~LoggerManager();
		LoggerManager(LoggerManager& instance) = delete;
		LoggerManager& operator=(const LoggerManager& instance) = delete;
	private:
		std::shared_ptr<spdlog::logger> m_pOptLog;
		std::shared_ptr<spdlog::logger> m_pRunLog;
		std::shared_ptr<spdlog::logger> m_pStdoutLog;
	};

#define Run_Log_Trace(...)			LoggerManager::GetInstance()->GetRunLogger()->trace(__VA_ARGS__)
#define Run_Log_Debug(...)			LoggerManager::GetInstance()->GetRunLogger()->debug(__VA_ARGS__)
#define Run_Log_Info(...)			LoggerManager::GetInstance()->GetRunLogger()->info(__VA_ARGS__)
#define Run_Log_Warn(...)			LoggerManager::GetInstance()->GetRunLogger()->warn(__VA_ARGS__)
#define Run_Log_Error(...)			LoggerManager::GetInstance()->GetRunLogger()->error(__VA_ARGS__)
#define Run_Log_Critical(...)		LoggerManager::GetInstance()->GetRunLogger()->critical(__VA_ARGS__)

#define Opt_Log_Trace(...)			LoggerManager::GetInstance()->GetOperatLogger()->trace(__VA_ARGS__)
#define Opt_Log_Debug(...)			LoggerManager::GetInstance()->GetOperatLogger()->debug(__VA_ARGS__)
#define Opt_Log_Info(...)			LoggerManager::GetInstance()->GetOperatLogger()->info(__VA_ARGS__)
#define Opt_Log_Warn(...)			LoggerManager::GetInstance()->GetOperatLogger()->warn(__VA_ARGS__)
#define Opt_Log_Error(...)			LoggerManager::GetInstance()->GetOperatLogger()->error(__VA_ARGS__)
#define Opt_Log_Critical(...)		LoggerManager::GetInstance()->GetOperatLogger()->critical(__VA_ARGS__)

#ifdef _DEBUG
#define Stdout_Log_Trace(...)		LoggerManager::GetInstance()->GetConsoleLogger()->trace(__VA_ARGS__)
#define Stdout_Log_Debug(...)		LoggerManager::GetInstance()->GetConsoleLogger()->debug(__VA_ARGS__)
#define Stdout_Log_Info(...)		LoggerManager::GetInstance()->GetConsoleLogger()->info(__VA_ARGS__)
#define Stdout_Log_Warn(...)		LoggerManager::GetInstance()->GetConsoleLogger()->warn(__VA_ARGS__)
#define Stdout_Log_Error(...)		LoggerManager::GetInstance()->GetConsoleLogger()->error(__VA_ARGS__)
#define Stdout_Log_Critical(...)	LoggerManager::GetInstance()->GetConsoleLogger()->critical(__VA_ARGS__)	
#else	
#define Stdout_Log_Trace(...)    
#define Stdout_Log_Debug(...)    
#define Stdout_Log_Info(...)     
#define Stdout_Log_Warn(...)     
#define Stdout_Log_Error(...)    
#define Stdout_Log_Critical(...) 

#endif // _DEBUG

}

