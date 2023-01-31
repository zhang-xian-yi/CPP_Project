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

	bool FuncMdlControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		m_bIsUse = true;



		return true;
	}

	bool FuncMdlControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{


		return true;
	}

	//���ؽ��
	bool FuncMdlControl::IsUse() const
	{
		return m_bIsUse;
	}

}