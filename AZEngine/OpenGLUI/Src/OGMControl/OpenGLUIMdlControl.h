#pragma once
#include "CMNInterface/IMdlOperat.h"
namespace OpenGLUINS
{
	class OpenGLUIMdlControl :public MdlCommonNS::IMdlOperat
	{
	public:
		OpenGLUIMdlControl();
		~OpenGLUIMdlControl();
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

