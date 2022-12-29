#pragma once
#include "Common/MarcoDefine.h"
namespace Log4CppNS
{
	//日志信息的参数
	struct LogerAPI LogMsgPara
	{
		char* message;//消息内容
		unsigned short length;//消息长度
	};

	class LogerAPI ILogger
	{
	public:
		virtual void LogMessage(LogMsgPara para) = 0;
	};
}