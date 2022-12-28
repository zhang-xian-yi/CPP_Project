#pragma once
namespace Log4CppNS
{
	//ǰ������
	class ILModule;
	class ILogger;

	//��־ģ��Ĺ���
	class LoggerFactory
	{
	public:
		ILogger* GetLoggerInstance();
		ILModule* GetModuleInstance();
	};
}


