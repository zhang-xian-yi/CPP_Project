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
	std::unique_ptr<MdlCommonNS::ISysResponse> LoggerControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		bool ret = para->IsValid();

		auto pResult = new MdlCommonNS::DefSysResponse();


		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}
	

}