#include "MdlScheduleControl.h"
#include <MSLogicService/MdlScheduleControlPrivate.h>
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"
namespace MdlScheduleNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	MdlScheduleControl::MdlScheduleControl()
		:m_pService(new MdlScheduleControlPrivate())
	{
	}
	/// <summary>
	/// 析构函数
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
	/// 执行调度逻辑
	/// </summary>
	/// <param name="para"></param>
	/// <returns></returns>
	MdlCommonNS::ISysResponse* MdlScheduleControl::DoService(const MdlCommonNS::ISysRequest* para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();


		return pResult;
	}
}