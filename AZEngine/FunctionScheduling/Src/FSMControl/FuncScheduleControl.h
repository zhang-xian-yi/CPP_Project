#pragma once
#include "CMNInterface/IMdlService.h"
#include "IFuncSchedule.h"

namespace FuncScheduleNS
{
	//ǰ������
	class CmdScheduleCtlPrivate;

	/// <summary>
	/// ����ģ����ȵ��߼�
	/// </summary>
	class FuncScheduleControl:public MdlCommonNS::IMdlService,public FuncScheduleNS::IFuncSchedule
	{
	public:
		FuncScheduleControl();
		~FuncScheduleControl();
	public:
		std::any ExecuteCmd(MdlCommonNS::ECommand cmd)override;
	private:
		CmdScheduleCtlPrivate* m_pCmdCtl;//����ʵ�ֵ�ҵ����ָ��
	};
}


