#pragma once

#include "CMNInterface/IMdlOperat.h"
namespace FuncScheduleNS
{
	/// <summary>
	/// ִ��ģ��ҵ����ȵķ���
	/// </summary>
	class FuncMdlControl:public MdlCommonNS::IMdlOperat
	{
	public:
		FuncMdlControl();
		~FuncMdlControl();
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


