#include "LoggerFactory.h"
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/IMdlService.h"
#include "LMControl/LModuleControl.h"
#include "LMControl/LoggerControl.h"
namespace Log4CppNS
{
	LoggerFactory::LoggerFactory()
	{
	}

	LoggerFactory::~LoggerFactory()
	{

	}
	/// <summary>
	/// ����һ����ҵ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* LoggerFactory::CreateServiceInstance()
	{
		return new Log4CppNS::LoggerControl();
	}
	/// <summary>
	/// ����һ����ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* LoggerFactory::CreateModuleInstance()
	{
		return new Log4CppNS::LModuleControl();
	}
}