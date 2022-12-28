#pragma once
#include "ILogger.h"
namespace Log4CppNS
{
	//日志打印控制工具
	class LoggerControl:public ILogger
	{
	public:
		void LogMessage(LogMsgPara para) override;
	};
}


