#include "LoggerControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

using namespace MdlCommonNS; //使用公共库的命名空间

namespace LoggerNS
{
	LoggerControl::LoggerControl()
	{
	}
	LoggerControl::~LoggerControl()
	{
	}
	//日志消息打印
	MdlCommonNS::ISysResponse* LoggerControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();


		return pResult;
	}
	

}