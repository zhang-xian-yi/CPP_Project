#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace FuncScheduleNS
{
	//ǰ������
	class CmdScheduleCtlPrivate;

	/// <summary>
	/// ����ģ����ȵ��߼�
	/// </summary>
	class FuncScheduleControl:public MdlCommonNS::IMdlService
	{
	public:
		FuncScheduleControl();
		~FuncScheduleControl();
	public:
		virtual MdlCommonNS::ISysResponse* DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para = nullptr) override;
	private:
		CmdScheduleCtlPrivate* m_pCmdCtl;//����ʵ�ֵ�ҵ����ָ��
	};
}


