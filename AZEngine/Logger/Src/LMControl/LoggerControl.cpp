#include "LoggerControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"
#include "LLogicService/LoggerManager.h"//��־����
using namespace MdlCommonNS; //ʹ�ù�����������ռ�

namespace LoggerNS
{
	LoggerControl::LoggerControl()
	{
	}
	LoggerControl::~LoggerControl()
	{
	}
	//��־��Ϣ��ӡ
	MdlCommonNS::ISysResponse* LoggerControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();


		return pResult;
	}
	

}