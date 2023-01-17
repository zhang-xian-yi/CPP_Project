#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace MdlScheduleNS
{
	//前置声明
	class MdlScheduleControlPrivate;

	/// <summary>
	/// 处理模块调度的逻辑
	/// </summary>
	class MdlScheduleControl:public MdlCommonNS::IMdlService
	{
	public:
		MdlScheduleControl();
		~MdlScheduleControl();
	public:
		MdlCommonNS::ISysResponse* DoService(const MdlCommonNS::ISysRequest* para);
	private:

	private:
		MdlScheduleControlPrivate* m_pService;//具体实现的业务类指针
	};
}


