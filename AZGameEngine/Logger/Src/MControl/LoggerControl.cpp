#include "LoggerControl.h"
#include "Common/LoggerGlobal.h"
#include "Entity/DefSysResponse.h"
#include "Entity/DefSysRequest.h"
namespace Log4CppNS
{
	LoggerControl::LoggerControl()
	{
	}
	LoggerControl::~LoggerControl()
	{
	}
	//日志消息打印
	CommonNS::ISysResponse* LoggerControl::DoService(const CommonNS::ISysRequest& para)
	{
		bool ret = para.IsValid();


		return new CommonNS::DefSysResponse();
	}
}