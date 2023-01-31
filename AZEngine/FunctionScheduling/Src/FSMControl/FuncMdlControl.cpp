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

	bool FuncMdlControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		m_bIsUse = true;



		return true;
	}

	bool FuncMdlControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{


		return true;
	}

	//返回结果
	bool FuncMdlControl::IsUse() const
	{
		return m_bIsUse;
	}

}