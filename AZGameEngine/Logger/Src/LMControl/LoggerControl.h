#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace Log4CppNS
{
	//��־��ӡ���ƹ���
	class LoggerControl:public MdlCommonNS::IMdlService
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual MdlCommonNS::ISysResponse* DoService(const MdlCommonNS::ISysRequest* para) override;
	};
}


