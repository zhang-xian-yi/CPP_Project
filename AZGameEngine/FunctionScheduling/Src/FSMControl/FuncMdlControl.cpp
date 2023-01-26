#include "FuncMdlControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

namespace FuncScheduleNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	FuncMdlControl::FuncMdlControl()
		:m_bIsUse(false)
	{

	}
	/// <summary>
	/// ��������
	/// </summary>
	FuncMdlControl::~FuncMdlControl()
	{

	}

	MdlCommonNS::ISysResponse* FuncMdlControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();



		return pResult;
	}

	MdlCommonNS::ISysResponse* FuncMdlControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return pResult;
	}

	//���ؽ��
	bool FuncMdlControl::IsUse() const
	{
		return m_bIsUse;
	}

}