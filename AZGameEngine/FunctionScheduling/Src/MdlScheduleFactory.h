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
	/// <summary>
	/// ���ܵ���ģ��Ĺ���
	/// </summary>
	class MdlScheduleDLLAPI MdlScheduleFactory:public MdlCommonNS::IMdlFactory
	{
	public:
		static MdlScheduleFactory* GetFactory()
		{
			static MdlScheduleFactory instance;
			return &instance;
		}
	public:
		MdlCommonNS::IMdlService* GetServiceInstance() override;
		MdlCommonNS::IMdlOperat* GetModuleInstance() override;
	private:
		//��ֹ�������幤������ֹdelelte ��������
		MdlScheduleFactory();
		~MdlScheduleFactory();
		MdlScheduleFactory(MdlScheduleFactory& instance) = delete;
		MdlScheduleFactory& operator=(const MdlScheduleFactory& instance) = delete;
	private:
		MdlCommonNS::IMdlService* m_pService;//ģ����ȵ�ҵ����ָ��
		MdlCommonNS::IMdlOperat* m_pModule;//ģ���ʼ���Լ���ͣ
	};
}


