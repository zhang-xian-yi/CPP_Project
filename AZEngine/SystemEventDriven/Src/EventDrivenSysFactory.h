#include "SEDCommon/SEDExpMarcoDefine.h"
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace SysEventDNS
{
	//��־ģ��Ĺ���
	class SysEventNSAPI EventDrivenSysFactory :public MdlCommonNS::IMdlFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonFactory(EventDrivenSysFactory)
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}
