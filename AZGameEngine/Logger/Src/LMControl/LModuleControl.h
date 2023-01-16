#pragma once
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"

namespace Log4CppNS
{
	class LModuleControl:public MdlCommonNS::IMdlOperat
	{
	public:
		LModuleControl();
		~LModuleControl();
	public:
		//����ģ��
		virtual MdlCommonNS::ISysResponse* ConstructModule(const MdlCommonNS::ISysRequest* para) override;
		//ע�ᵽģ����ȳ�����,��Ҫ��ȡģ����ȵķ����������ã�������ʵ���˽ӿڵ�ʵ����ע�ᵽ������
		virtual MdlCommonNS::ISysResponse* RegisterModule(const MdlCommonNS::ISysRequest* para) override;
		//����ģ��
		virtual MdlCommonNS::ISysResponse* DestoryModule(const MdlCommonNS::ISysRequest* para) override;
		//ע��ģ����ȳ����еĹ���ģ��,��Ҫ��ȡģ����ȵķ����������ã�������ʵ���˽ӿڵ�ʵ����ӷ����������Ƴ�
		virtual MdlCommonNS::ISysResponse* UnRegisterModule(const MdlCommonNS::ISysRequest* para) override;
		//��ȡģ��״̬
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//ģ���Ƿ����
	};
}


