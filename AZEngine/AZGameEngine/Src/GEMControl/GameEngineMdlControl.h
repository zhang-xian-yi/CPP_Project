#pragma once
#include "CMNInterface/IMdlOperat.h"

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
		virtual bool ConstructModule() override;
		//����ģ��
		virtual bool DestoryModule() override;
		//��ȡģ��״̬
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//ģ���Ƿ����
	};
}


