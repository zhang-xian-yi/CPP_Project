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
		virtual MdlCommonNS::ISysResponse* ConstructModule(const MdlCommonNS::ISysRequest* para = nullptr) override;
		//����ģ��
		virtual MdlCommonNS::ISysResponse* DestoryModule(const MdlCommonNS::ISysRequest* para = nullptr) override;
		//��ȡģ��״̬
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//ģ���Ƿ����
	};
}


