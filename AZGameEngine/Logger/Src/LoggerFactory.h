#pragma once
#include "LCommon/LExpMarcoDefine.h"
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace Log4CppNS
{
	//��־ģ��Ĺ���
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


