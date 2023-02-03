#include "FuncScheduleFactory.h"
//ʵ����
#include <FSMControl/FuncMdlControl.h>
#include <FSMControl/FuncScheduleControl.h>
//�ⲿͷ�ļ�
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"

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