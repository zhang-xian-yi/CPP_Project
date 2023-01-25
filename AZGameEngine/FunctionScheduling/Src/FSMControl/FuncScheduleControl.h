#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace FuncScheduleNS
{
	//ǰ������
	class FuncScheduleCtlPrivate;

	/// <summary>
	/// ����ģ����ȵ��߼�
	/// </summary>
	class FuncScheduleControl:public MdlCommonNS::IMdlService
	{
	public:
		FuncScheduleControl();
		~FuncScheduleControl();
	public:
		virtual std::unique_ptr<MdlCommonNS::ISysResponse> DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para = nullptr) override;
	private:
		FuncScheduleCtlPrivate* m_pService;//����ʵ�ֵ�ҵ����ָ��
	};
}


