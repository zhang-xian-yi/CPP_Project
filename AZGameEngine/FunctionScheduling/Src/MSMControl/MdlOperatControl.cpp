#include "MdlOperatControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"
namespace MdlScheduleNS
{

	/// <summary>
	/// ���캯��
	/// </summary>
	MdlOperatControl::MdlOperatControl()
		:m_bIsUse(false)
	{

	}
	/// <summary>
	/// ��������
	/// </summary>
	MdlOperatControl::~MdlOperatControl()
	{

	}

	MdlCommonNS::ISysResponse* MdlOperatControl::ConstructModule(const MdlCommonNS::ISysRequest* para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();
		

		return pResult;
	}
	MdlCommonNS::ISysResponse* MdlOperatControl::DestoryModule(const MdlCommonNS::ISysRequest* para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();


		return pResult;
	}


	//���ؽ��
	bool MdlOperatControl::IsUse() const
	{
		return m_bIsUse;
	}

}