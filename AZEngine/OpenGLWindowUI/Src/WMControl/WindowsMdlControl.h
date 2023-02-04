#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"
namespace WindowsNS
{
	class WindowsMdlControl :public MdlCommonNS::IMdlOperat
	{
	public:
		WindowsMdlControl();
		~WindowsMdlControl();
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

