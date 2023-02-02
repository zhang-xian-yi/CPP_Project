#pragma once
//�������й���ģ��Ĺ�����Լ��
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <CMNInterface/IMdlOperat.h>
#include <CMNInterface/IMdlService.h>

namespace MdlCommonNS
{
	//ģ��ҵ���߼��ӿ�
	class MdlCommonDLLAPI IMdlFactory
	{
	public:
		virtual ~IMdlFactory() = 0;
	public:
		//����Get ������ʵ�ֱ�����ڹ�������ʵ������䣬����Ϊconst�����Թ���ָ��Ҳ������const
		//���ﲻ��������ָ�룬��Ϊģ��Ϳ��ƾ���unique_ptr ���й���
		virtual MdlCommonNS::IMdlService* CreateServiceInstance() = 0;
		virtual MdlCommonNS::IMdlOperat*  CreateModuleInstance() = 0;
	};

#define SingletonFactory(type)  	private:\
									type() = default;\
									~type()= default;\
									type(type& instance) = delete;\
									type& operator=(const type& instance) = delete;\
									public:\
									static MdlCommonNS::IMdlFactory* GetFactory()\
									{\
										static type instance;\
										return &instance;\
									}
}