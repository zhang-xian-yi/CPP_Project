#pragma once
#include "CMNInterface/IMdlOperat.h"

namespace AZDataComputeNS
{
	//��Ϸ�����ģ�������
	class DataComputeMdlControl :public MdlCommonNS::IMdlOperat
	{
	public:
		DataComputeMdlControl();
		~DataComputeMdlControl();
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


