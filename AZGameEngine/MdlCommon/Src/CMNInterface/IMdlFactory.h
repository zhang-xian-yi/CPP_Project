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
}