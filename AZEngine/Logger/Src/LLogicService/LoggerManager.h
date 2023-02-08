#pragma once
#include <memory>
#include <string>
#include "MdlCommon/Src/CMNMacro/CoreMacroDef.h"
#include "BaseSpdlog.h"

namespace LoggerNS
{
	/// <summary>
	/// 输出到控制台的业务逻辑
	/// </summary>
	class LoggerManager
	{
		SingletonSelfConstruct(LoggerManager)
	public:
		//获取日志实例
		std::shared_ptr<spdlog::logger> GetFileLogger();
		std::shared_ptr<spdlog::logger> GetStdoutLogger();
		//销毁
		void Destory();
		//初始化
		void Init();
	private:
		OptLogBase* m_pFileLog;
		OptLogBase* m_pStdoutLog;
	};

#define Run_Log_Trace(...)			LoggerManager::GetInstance().GetFileLogger()->trace(__VA_ARGS__)
#define Run_Log_Debug(...)			LoggerManager::GetInstance().GetFileLogger()->debug(__VA_ARGS__)
#define Run_Log_Info(...)			LoggerManager::GetInstance().GetFileLogger()->info(__VA_ARGS__)
#define Run_Log_Warn(...)			LoggerManager::GetInstance().GetFileLogger()->warn(__VA_ARGS__)
#define Run_Log_Error(...)			LoggerManager::GetInstance().GetFileLogger()->error(__VA_ARGS__)
#define Run_Log_Critical(...)		LoggerManager::GetInstance().GetFileLogger()->critical(__VA_ARGS__)

#ifdef _DEBUG
#define Stdout_Log_Trace(...)		LoggerManager::GetInstance().GetStdoutLogger()->trace(__VA_ARGS__)
#define Stdout_Log_Debug(...)		LoggerManager::GetInstance().GetStdoutLogger()->debug(__VA_ARGS__)
#define Stdout_Log_Info(...)		LoggerManager::GetInstance().GetStdoutLogger()->info(__VA_ARGS__)
#define Stdout_Log_Warn(...)		LoggerManager::GetInstance().GetStdoutLogger()->warn(__VA_ARGS__)
#define Stdout_Log_Error(...)		LoggerManager::GetInstance().GetStdoutLogger()->error(__VA_ARGS__)
#define Stdout_Log_Critical(...)	LoggerManager::GetInstance().GetStdoutLogger()->critical(__VA_ARGS__)	
#else	
#define Stdout_Log_Trace(...)    
#define Stdout_Log_Debug(...)    
#define Stdout_Log_Info(...)     
#define Stdout_Log_Warn(...)     
#define Stdout_Log_Error(...)    
#define Stdout_Log_Critical(...) 

#endif // _DEBUG

}

