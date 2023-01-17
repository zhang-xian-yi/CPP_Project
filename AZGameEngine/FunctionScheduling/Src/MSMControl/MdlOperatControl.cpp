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


	//返回结果
	bool MdlOperatControl::IsUse() const
	{
		return m_bIsUse;
	}

}