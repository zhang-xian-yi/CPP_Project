#include "StopAndUnRegisterAllService.h"
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"//ģ������ӿ�
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"//ģ������
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