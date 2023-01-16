#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace Log4CppNS
{
	//日志打印控制工具
	class LoggerControl:public MdlCommonNS::IMdlService
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual MdlCommonNS::ISysResponse* DoService(const MdlCommonNS::ISysRequest* para) override;
	};
}


