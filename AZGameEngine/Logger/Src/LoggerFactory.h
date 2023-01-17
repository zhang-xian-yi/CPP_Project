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
		static MdlCommonNS::IMdlFactory* GetFactory()
		{
			static LoggerFactory instance;
			return &instance;
		}
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	private:
		//��ֹ�������幤������ֹdelelte ��������
		LoggerFactory();
		~LoggerFactory();
		LoggerFactory(LoggerFactory& instance) = delete;
		LoggerFactory& operator=(const LoggerFactory& instance) = delete;
	};
}


