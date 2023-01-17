#include "MdlOperatControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

namespace MdlScheduleNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	MdlOperatControl::MdlOperatControl()
		:m_bIsUse(false)
	{

	}
	/// <summary>
	/// 析构函数
	/// </summary>
	MdlOperatControl::~MdlOperatControl()
	{

	}

	std::unique_ptr<MdlCommonNS::ISysResponse> MdlOperatControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}

	std::unique_ptr<MdlCommonNS::ISysResponse> MdlOperatControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}

	//返回结果
	bool MdlOperatControl::IsUse() const
	{
		return m_bIsUse;
	}

}