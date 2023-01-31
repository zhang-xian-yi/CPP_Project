#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace LoggerNS
{
	//��־��ӡ���ƹ���
	class LoggerControl:public MdlCommonNS::IMdlService
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual MdlCommonNS::ISysResponse* DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para = nullptr) override;
	};
}


