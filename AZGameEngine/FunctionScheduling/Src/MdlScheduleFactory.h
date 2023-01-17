#pragma once
#include <MSCommon/MSExpMarcoDefine.h>
#include <MSCommon/MSExpMarcoDefine.h>
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace MdlScheduleNS
{
	/// <summary>
	/// 功能调度模块的工厂
	/// </summary>
	class MdlScheduleDLLAPI MdlScheduleFactory:public MdlCommonNS::IMdlFactory
	{
	public:
		static MdlCommonNS::IMdlFactory* GetFactory()
		{
			static MdlScheduleFactory instance;
			return &instance;
		}
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	private:
		//禁止反复定义工厂，禁止delelte 工厂对象
		MdlScheduleFactory();
		~MdlScheduleFactory();
		MdlScheduleFactory(MdlScheduleFactory& instance) = delete;
		MdlScheduleFactory& operator=(const MdlScheduleFactory& instance) = delete;
	};
}


