#include "LoggerFactory.h"
#include "LMControl/LModuleControl.h"
#include "LMControl/LoggerControl.h"
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"

namespace LoggerNS
{
	/// <summary>
	/// ����һ����ҵ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* LoggerFactory::CreateServiceInstance()
	{
		return new LoggerNS::LoggerControl();
	}
	/// <summary>
	/// ����һ����ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* LoggerFactory::CreateModuleInstance()
	{
		return new LoggerNS::LModuleControl();
	}
}