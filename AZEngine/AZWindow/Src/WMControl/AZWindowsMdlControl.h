#pragma once
#include "CMNInterface/IMdlOperat.h"
namespace AZWindowsNS
{
	class AZWindowsMdlControl :public MdlCommonNS::IMdlOperat
	{
	public:
		AZWindowsMdlControl();
		~AZWindowsMdlControl();
	public:
		//����ģ��
		virtual bool ConstructModule() override;
		//����ģ��
		virtual bool DestoryModule() override;
		//��ȡģ��״̬
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//ģ���Ƿ����
	};

}

