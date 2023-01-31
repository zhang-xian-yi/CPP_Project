#pragma once
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"

namespace AZGameEngineNS
{
	//��Ϸ�����ģ�������
	class GameEngineMdlControl :public MdlCommonNS::IMdlOperat
	{
	public:
		GameEngineMdlControl();
		~GameEngineMdlControl();
	public:
		//����ģ��
		virtual bool ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
		//����ģ��
		virtual bool DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
		//��ȡģ��״̬
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//ģ���Ƿ����
	};
}


