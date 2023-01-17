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
	MdlCommonNS::ISysResponse* MdlScheduleControl::DoService(const MdlCommonNS::ISysRequest* para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();


		return pResult;
	}
}