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
		static MdlCommonNS::IMdlFactory* GetFactory()
		{
			static LoggerFactory instance;
			return &instance;
		}
	public:
		virtual MdlCommonNS::IMdlService* GetServiceInstance() override;
		virtual MdlCommonNS::IMdlOperat* GetModuleInstance() override;
	private:

	private:
		//禁止反复定义工厂，禁止delelte 工厂对象
		LoggerFactory();
		~LoggerFactory();
		LoggerFactory(LoggerFactory& instance) = delete;
		LoggerFactory& operator=(const LoggerFactory& instance) = delete;
	private:
		MdlCommonNS::IMdlService* m_pService;
		MdlCommonNS::IMdlOperat* m_pModule;
	};
}


