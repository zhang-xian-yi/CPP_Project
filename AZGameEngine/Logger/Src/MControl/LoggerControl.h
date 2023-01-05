#pragma once
#include "Interface/IMdlService.h"
#include "Interface/ISysRequest.h"
#include "Interface/ISysResponse.h"
namespace Log4CppNS
{
	//日志打印控制工具
	class LoggerControl:public CommonNS::IMdlService
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual CommonNS::ISysResponse* DoService(const CommonNS::ISysRequest& para) override;
	};
}


