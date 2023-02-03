#pragma once
#include "CMNInterface/IMdlService.h"
#include "ILogger.h"
namespace LoggerNS
{
	//日志打印控制工具
	class LoggerControl
		:public MdlCommonNS::IMdlService,
		 public LoggerNS::IFileLogger,
		 public LoggerNS::IStdoutLogger
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual void LogFileMsgAsync(ELogLevel logLv, const std::string&& msg)override;
		virtual void LogStdoutMsgAsync(ELogLevel logLv, const std::string&& msg)override;
	private:
		void LogFileMsg(ELogLevel logLv, const std::string&& msg);
		void LogStdoutMsg(ELogLevel logLv, const std::string&& msg);
	};
}


