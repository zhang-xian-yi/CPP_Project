#include "FuncScheduleFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/IMdlOperat.h"
//ʵ����
#include <FSMControl/FuncMdlControl.h>
#include <FSMControl/FuncScheduleControl.h>
namespace FuncScheduleNS
{
	/// <summary>
	/// ����һ���µ�ҵ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* FuncScheduleFactory::CreateServiceInstance()
	{
		return new FuncScheduleNS::FuncScheduleControl();
	}

	/// <summary>
	/// ����һ���µ�ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* FuncScheduleFactory::CreateModuleInstance()
	{
		return new FuncScheduleNS::FuncMdlControl();
	}
}