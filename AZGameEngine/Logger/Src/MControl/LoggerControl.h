#pragma once
#include "ILogger.h"
namespace Log4CppNS
{
	//��־��ӡ���ƹ���
	class LoggerControl:public ILogger
	{
	public:
		void LogMessage(LogMsgPara para) override;
	};
}


