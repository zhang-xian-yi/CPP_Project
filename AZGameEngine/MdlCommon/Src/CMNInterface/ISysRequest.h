#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <CMNEntity/Any.h>
/*
Լ����ϵͳ������ڴ�����ɷ������룬���շ�����
Լ�������н���ͨѶ��ϵͳ���󣬾�������ָ�����

*/

namespace MdlCommonNS
{
	//ϵͳ��������
	class MdlCommonDLLAPI ISysRequest
	{
	public:
		virtual ~ISysRequest() = 0;
	public:
		//Լ����ȡ�����������ݵķ���
		virtual Any& GetData()const = 0;
	};
}