#pragma once
#include "CMNInterface/IMdlService.h"
#include "ILogger.h"
namespace LoggerNS
{
	//日志打印控制工具
	class LoggerControl:public MdlCommonNS::IMdlService,public LoggerNS::IRunLogger
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual void LogRunInfoMsg();
	};
}


