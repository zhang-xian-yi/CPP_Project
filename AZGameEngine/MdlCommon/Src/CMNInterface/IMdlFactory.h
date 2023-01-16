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
		virtual MdlCommonNS::IMdlService* GetServiceInstance() = 0;
		virtual MdlCommonNS::IMdlOperat* GetModuleInstance() = 0;
	};
}