#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace Log4CppNS
{
	//��־��ӡ���ƹ���
	class LoggerControl:public CommonNS::IMdlService
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual CommonNS::ISysResponse* DoService(const CommonNS::ISysRequest* para) override;
	};
}


