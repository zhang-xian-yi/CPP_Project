#include "MdlScheduleControl.h"
#include <MSLogicService/MdlScheduleControlPrivate.h>
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"
namespace MdlScheduleNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	MdlScheduleControl::MdlScheduleControl()
		:m_pService(new MdlScheduleControlPrivate())
	{
	}
	/// <summary>
	/// ��������
	/// </summary>
	MdlScheduleControl::~MdlScheduleControl()
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
	std::unique_ptr<MdlCommonNS::ISysResponse> MdlScheduleControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();


		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}
}