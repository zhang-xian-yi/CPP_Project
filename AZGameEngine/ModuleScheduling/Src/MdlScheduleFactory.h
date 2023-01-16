#pragma once
#include <MSCommon/MSExpMarcoDefine.h>
#include <MSCommon/MSExpMarcoDefine.h>
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace MdlScheduleNS
{
	class MdlScheduleDLLAPI MdlScheduleFactory:public MdlCommonNS::IMdlFactory
	{
	public:
		static MdlScheduleFactory& GetFactory()
		{
			static MdlScheduleFactory instance;
			return instance;
		}
	public:
		MdlScheduleFactory();
		~MdlScheduleFactory();

		MdlCommonNS::IMdlService* GetServiceInstance() override;
		MdlCommonNS::IMdlOperat* GetModuleInstance() override;
	private:
		MdlCommonNS::IMdlService* m_pService;//ģ����ȵ�ҵ����ָ��
		MdlCommonNS::IMdlOperat* m_pModule;//ģ���ʼ���Լ���ͣ
	};
}


