#pragma once
#include "Interface/IMdlService.h"
#include "Interface/ISysRequest.h"
#include "Interface/ISysResponse.h"
namespace Log4CppNS
{
	//��־��ӡ���ƹ���
	class LoggerControl:public CommonNS::IMdlService
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual CommonNS::ISysResponse* DoService(const CommonNS::ISysRequest& para) override;
	};
}


