#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"

namespace EventDrivenSysNS
{
	//��Ϸ�����ģ�������
	class EventDrivenSysMdlControl :public MdlCommonNS::IMdlOperat
	{
	public:
		EventDrivenSysMdlControl();
		~EventDrivenSysMdlControl();
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


