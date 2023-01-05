#pragma once
#include "Common/MarcoDefine.h"

namespace CommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace Log4CppNS
{
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

		CommonNS::IMdlService* GetLoggerInstance();
		CommonNS::IMdlOperat* GetModuleInstance();
	private:
		CommonNS::IMdlService* m_pLog;
		CommonNS::IMdlOperat* m_pModule;
	};
}


