#pragma once
#include "LCommon/LExpMarcoDefine.h"

namespace MdlCommonNS
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

		MdlCommonNS::IMdlService* GetLoggerInstance();
		MdlCommonNS::IMdlOperat* GetModuleInstance();
	private:
		MdlCommonNS::IMdlService* m_pLog;
		MdlCommonNS::IMdlOperat* m_pModule;
	};
}


