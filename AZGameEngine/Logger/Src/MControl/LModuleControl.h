#pragma once
#include "Interface/IMdlOperat.h"
#include "Interface/ISysRequest.h"
#include "Interface/ISysResponse.h"

namespace Log4CppNS
{
	class LModuleControl:public CommonNS::IMdlOperat
	{
	public:
		LModuleControl();
		~LModuleControl();
	public:
		//����ģ��
		virtual CommonNS::ISysResponse* ConstructModule(const CommonNS::ISysRequest& para) override;
		//ע�ᵽģ����ȳ�����,��Ҫ��ȡģ����ȵķ����������ã�������ʵ���˽ӿڵ�ʵ����ע�ᵽ������
		virtual CommonNS::ISysResponse* RegisterModule(const CommonNS::ISysRequest& para) override;
		//����ģ��
		virtual CommonNS::ISysResponse* DestoryModule(const CommonNS::ISysRequest& para) override;
		//ע��ģ����ȳ����еĹ���ģ��,��Ҫ��ȡģ����ȵķ����������ã�������ʵ���˽ӿڵ�ʵ����ӷ����������Ƴ�
		virtual CommonNS::ISysResponse* UnRegisterModule(const CommonNS::ISysRequest& para) override;
		//��ȡģ��״̬
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//ģ���Ƿ����
	};
}


