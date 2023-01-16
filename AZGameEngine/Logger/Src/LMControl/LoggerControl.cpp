#include "LoggerControl.h"
#include <LCommon/LoggerGlobal.h>
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

using namespace MdlCommonNS; //使用公共库的命名空间

namespace Log4CppNS
{
	LoggerControl::LoggerControl()
	{
	}
	LoggerControl::~LoggerControl()
	{
	}
	//日志消息打印
	ISysResponse* LoggerControl::DoService(const ISysRequest* para)
	{
		bool ret = para->IsValid();


		return new DefSysResponse();
	}
}