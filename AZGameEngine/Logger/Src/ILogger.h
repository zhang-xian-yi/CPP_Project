#pragma once
namespace Log4CppNS
{
	//��־��Ϣ�Ĳ���
	struct LogMsgPara
	{
		char* message;//��Ϣ����
		unsigned short length;//��Ϣ����
	};

	class ILogger
	{
	public:
		virtual void LogMessage(LogMsgPara para) = 0;
	};
}