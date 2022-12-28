#pragma once
namespace Log4CppNS
{
	//日志信息的参数
	struct LogMsgPara
	{
		char* message;//消息内容
		unsigned short length;//消息长度
	};

	class ILogger
	{
	public:
		virtual void LogMessage(LogMsgPara para) = 0;
	};
}