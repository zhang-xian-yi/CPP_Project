#pragma once
#include "CMNInterface/IMdlService.h"
#include "ILogger.h"
namespace LoggerNS
{
	//��־��ӡ���ƹ���
	class LoggerControl:public MdlCommonNS::IMdlService,public LoggerNS::IRunLogger
	{
	public:
		LoggerControl();
		~LoggerControl();
	public:
		virtual void LogRunInfoMsg();
	};
}


