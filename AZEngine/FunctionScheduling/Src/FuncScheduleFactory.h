#pragma once
#include "FSCommon/MSExpMarcoDefine.h"
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace FuncScheduleNS
{
	/// <summary>
	/// ���ܵ���ģ��Ĺ���
	/// </summary>
	class MdlScheduleDLLAPI FuncScheduleFactory:public MdlCommonNS::IMdlFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonFactory(FuncScheduleFactory)
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	};
}


