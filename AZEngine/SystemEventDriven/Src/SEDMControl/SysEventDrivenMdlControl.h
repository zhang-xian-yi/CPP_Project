#pragma once
#include "CMNInterface/IMdlOperat.h"

namespace SysEventDNS
{
	//��Ϸ�����ģ�������
	class SysEventDrivenMdlControl :public MdlCommonNS::IMdlOperat
	{
	public:
		SysEventDrivenMdlControl();
		~SysEventDrivenMdlControl();
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


