#include "LoggerControl.h"
#include "Common/LoggerGlobal.h"
#include "Entity/DefSysResponse.h"
#include "Entity/DefSysRequest.h"
namespace Log4CppNS
{
	LoggerControl::LoggerControl()
	{
	}
	LoggerControl::~LoggerControl()
	{
	}
	//��־��Ϣ��ӡ
	CommonNS::ISysResponse* LoggerControl::DoService(const CommonNS::ISysRequest& para)
	{
		bool ret = para.IsValid();


		return new CommonNS::DefSysResponse();
	}
}