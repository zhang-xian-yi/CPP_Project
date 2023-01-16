#pragma once
#include "LCommon/LExpMarcoDefine.h"
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace Log4CppNS
{
	//日志模块的工厂
	class LogerAPI LoggerFactory :public MdlCommonNS::IMdlFactory
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

		virtual MdlCommonNS::IMdlService* GetServiceInstance() override;
		virtual MdlCommonNS::IMdlOperat* GetModuleInstance() override;
	private:
		MdlCommonNS::IMdlService* m_pService;
		MdlCommonNS::IMdlOperat* m_pModule;
	};
}


