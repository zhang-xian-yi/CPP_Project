#pragma once

#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace MdlScheduleNS
{
	/// <summary>
	/// ִ��ģ��ҵ����ȵķ���
	/// </summary>
	class MdlOperatControl:public MdlCommonNS::IMdlOperat
	{
	public:
		MdlOperatControl();
		~MdlOperatControl();
	public:
		//����ģ��
		virtual std::unique_ptr<MdlCommonNS::ISysResponse> ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
		//����ģ��
		virtual std::unique_ptr<MdlCommonNS::ISysResponse> DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
		//��ȡģ��״̬
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//ģ���Ƿ����
	};
}


