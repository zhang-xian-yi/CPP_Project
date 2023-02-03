#include "SEDCommon/SEDExpMarcoDefine.h"
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//前置声明
	class IMdlOperat;
	class IMdlService;
}

namespace SysEventDNS
{
	//日志模块的工厂
	class SysEventNSAPI EventDrivenSysFactory :public MdlCommonNS::IMdlFactory
	{
		//禁止反复定义工厂，禁止delelte 工厂对象
		SingletonFactory(EventDrivenSysFactory)
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}
