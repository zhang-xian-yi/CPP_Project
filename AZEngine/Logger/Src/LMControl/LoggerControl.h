#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace LoggerNS
{
	//日志打印控制工具
	class LoggerControl:public MdlCommonNS::IMdlService
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual MdlCommonNS::ISysResponse* DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para = nullptr) override;
	};
}


