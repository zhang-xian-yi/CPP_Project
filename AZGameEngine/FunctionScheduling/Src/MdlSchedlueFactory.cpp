#include "MdlScheduleFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/IMdlOperat.h"
//ʵ����
#include <MSMControl/MdlOperatControl.h>
#include <MSMControl/MdlScheduleControl.h>
namespace MdlScheduleNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	MdlScheduleFactory::MdlScheduleFactory()
	{
	}
	/// <summary>
	/// ��������
	/// </summary>
	MdlScheduleFactory::~MdlScheduleFactory()
	{

	}

	/// <summary>
	/// ����һ���µ�ҵ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* MdlScheduleFactory::CreateServiceInstance()
	{
		return new MdlScheduleNS::MdlScheduleControl();
	}

	/// <summary>
	/// ����һ���µ�ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* MdlScheduleFactory::CreateModuleInstance()
	{
		return new MdlScheduleNS::MdlOperatControl();
	}
}