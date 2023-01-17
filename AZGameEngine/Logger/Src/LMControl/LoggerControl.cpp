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
	std::unique_ptr<MdlCommonNS::ISysResponse> LoggerControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		bool ret = para->IsValid();

		auto pResult = new MdlCommonNS::DefSysResponse();


		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}
	

}