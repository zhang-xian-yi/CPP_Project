#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <CMNEntity/Any.h>
/*
Լ����ϵͳ��Ӧ���ڴ�����ɷ������룬���շ�����
Լ�������н���ͨѶ��ϵͳ��Ӧ����������ָ�����

*/

namespace MdlCommonNS
{
	//ϵͳ������Ӧ
	class MdlCommonDLLAPI ISysResponse
	{
	public:
		virtual ~ISysResponse() = 0;
	public:
		//Լ����ȡ�����������ݵķ���
		virtual Any& GetData()const = 0;
	};
}