#include "StopAndUnRegisterAllService.h"
#include "CMNInterface/IMdlOperat.h"//ģ������ӿ�
#include "CMNInterface/IMdlFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"//Ĭ���������Ӧ
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "CMNMEnum/ModuelType/EModuleType.h"//ģ������
namespace FuncScheduleNS
{
	/// <summary>
	/// ҵ���߼��ӿ�
	/// </summary>
	void StopAndUnRegisterAllService::DoService()
	{
		MdlCommonNS::ServiceContainerSingle::GetContainer().DestoryContaineer();
	}
}