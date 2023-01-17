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
		static MdlCommonNS::IMdlFactory* GetFactory()
		{
			static MdlScheduleFactory instance;
			return &instance;
		}
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	private:
		//��ֹ�������幤������ֹdelelte ��������
		MdlScheduleFactory();
		~MdlScheduleFactory();
		MdlScheduleFactory(MdlScheduleFactory& instance) = delete;
		MdlScheduleFactory& operator=(const MdlScheduleFactory& instance) = delete;
	};
}


