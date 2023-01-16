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
	class MdlScheduleDLLAPI MdlScheduleFactory:public MdlCommonNS::IMdlFactory
	{
	public:
		static MdlScheduleFactory& GetFactory()
		{
			static MdlScheduleFactory instance;
			return instance;
		}
	public:
		MdlScheduleFactory();
		~MdlScheduleFactory();

		MdlCommonNS::IMdlService* GetServiceInstance() override;
		MdlCommonNS::IMdlOperat* GetModuleInstance() override;
	private:
		MdlCommonNS::IMdlService* m_pService;//模块调度的业务类指针
		MdlCommonNS::IMdlOperat* m_pModule;//模块初始化以及启停
	};
}


