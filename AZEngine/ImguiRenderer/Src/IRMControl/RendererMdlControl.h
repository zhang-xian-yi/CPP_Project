#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"
namespace ImguiRendererNS
{
	class RendererMdlControl:MdlCommonNS::IMdlOperat
	{
	public:
		RendererMdlControl()=default;
		~RendererMdlControl() = default;
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

