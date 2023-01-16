#include "LoggerControl.h"
#include <LCommon/LoggerGlobal.h>
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

using namespace MdlCommonNS; //ʹ�ù�����������ռ�

namespace Log4CppNS
{
	LoggerControl::LoggerControl()
	{
	}
	LoggerControl::~LoggerControl()
	{
	}
	//��־��Ϣ��ӡ
	ISysResponse* LoggerControl::DoService(const ISysRequest* para)
	{
		bool ret = para->IsValid();


		return new DefSysResponse();
	}
}