#pragma once
#include "Common/MarcoDefine.h"
namespace Log4CppNS
{
	//��־��Ϣ�Ĳ���
	struct LogerAPI LogMsgPara
	{
		char* message;//��Ϣ����
		unsigned short length;//��Ϣ����
	};

	class LogerAPI ILogger
	{
	public:
		virtual void LogMessage(LogMsgPara para) = 0;
	};
}