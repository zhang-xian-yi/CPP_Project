#include "MdlScheduleFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/IMdlOperat.h"
//实现类
#include <MSMControl/MdlOperatControl.h>
#include <MSMControl/MdlScheduleControl.h>
namespace MdlScheduleNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	MdlScheduleFactory::MdlScheduleFactory()
	{
	}
	/// <summary>
	/// 析构函数
	/// </summary>
	MdlScheduleFactory::~MdlScheduleFactory()
	{

	}

	/// <summary>
	/// 创建一个新的业务控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* MdlScheduleFactory::CreateServiceInstance()
	{
		return new MdlScheduleNS::MdlScheduleControl();
	}

	/// <summary>
	/// 创建一个新的模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* MdlScheduleFactory::CreateModuleInstance()
	{
		return new MdlScheduleNS::MdlOperatControl();
	}
}