#include "FuncMdlControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

namespace FuncScheduleNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	FuncMdlControl::FuncMdlControl()
		:m_bIsUse(false)
	{

	}
	/// <summary>
	/// 析构函数
	/// </summary>
	FuncMdlControl::~FuncMdlControl()
	{

	}

	std::unique_ptr<MdlCommonNS::ISysResponse> FuncMdlControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();



		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}

	std::unique_ptr<MdlCommonNS::ISysResponse> FuncMdlControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}

	//返回结果
	bool FuncMdlControl::IsUse() const
	{
		return m_bIsUse;
	}

}