#pragma once
#include <FSCommon/MSExpMarcoDefine.h>
#include "CMNInterface/IMdlFactory.h"
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
	public:
		static MdlCommonNS::IMdlFactory* GetFactory()
		{
			static FuncScheduleFactory instance;
			return &instance;
		}
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	private:
		//��ֹ�������幤������ֹdelelte ��������
		FuncScheduleFactory();
		~FuncScheduleFactory();
		FuncScheduleFactory(FuncScheduleFactory& instance) = delete;
		FuncScheduleFactory& operator=(const FuncScheduleFactory& instance) = delete;
	};
}


