#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace MdlScheduleNS
{
	//ǰ������
	class MdlScheduleControlPrivate;

	/// <summary>
	/// ����ģ����ȵ��߼�
	/// </summary>
	class MdlScheduleControl:public MdlCommonNS::IMdlService
	{
	public:
		MdlScheduleControl();
		~MdlScheduleControl();
	public:
		virtual std::unique_ptr<MdlCommonNS::ISysResponse> DoService(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
	private:

	private:
		MdlScheduleControlPrivate* m_pService;//����ʵ�ֵ�ҵ����ָ��
	};
}


