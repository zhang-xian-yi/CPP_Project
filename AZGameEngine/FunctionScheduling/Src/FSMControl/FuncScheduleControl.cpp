#include "FuncScheduleControl.h"
#include <FSLogicService/FuncScheduleCtlPrivate.h>
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"
#include "CMNMEnum/Command/ECommand.h"
namespace FuncScheduleNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	FuncScheduleControl::FuncScheduleControl()
		:m_pService(new FuncScheduleCtlPrivate())
	{
	}
	/// <summary>
	/// ��������
	/// </summary>
	FuncScheduleControl::~FuncScheduleControl()
	{
		if (m_pService != nullptr)
		{
			delete m_pService;
			m_pService = nullptr;
		}
	}
	/// <summary>
	/// ִ�е����߼�
	/// </summary>
	/// <param name="para"></param>
	/// <returns></returns>
	std::unique_ptr<MdlCommonNS::ISysResponse> FuncScheduleControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		std::any& requestData = para->GetData();
		MdlCommonNS::ECommand cmd = std::any_cast<MdlCommonNS::ECommand>(requestData);

		auto pResult = new MdlCommonNS::DefSysResponse();
		
		
		pResult->SetData(*(new std::any(true)));
		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}
}