#pragma once
#include "CMNInterface/IMdlService.h"
#include "ILogger.h"
namespace LoggerNS
{
	//��־��ӡ���ƹ���
	class LoggerControl
		:public MdlCommonNS::IMdlService,
		 public LoggerNS::IFileLogger,
		 public LoggerNS::IStdoutLogger
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual void LogFileMsg(ELogLevel logLv, const std::string&& msg)override;
		virtual void LogStdoutMsg(ELogLevel logLv, const std::string&& msg)override;
	};
}


