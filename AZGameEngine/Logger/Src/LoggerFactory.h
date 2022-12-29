#pragma once
#include "Common/MarcoDefine.h"

namespace Log4CppNS
{
	//ǰ������
	class ILModule;
	class ILogger;

	//��־ģ��Ĺ���
	class LogerAPI LoggerFactory
	{
	public:
		static LoggerFactory& GetFactory()
		{
			static LoggerFactory instance;
			return instance;
		}
	public:
		LoggerFactory();
		~LoggerFactory();

		ILogger* GetLoggerInstance();
		ILModule* GetModuleInstance();
	private:
		ILogger* m_pLog;
		ILModule* m_pModule;
	};
}


