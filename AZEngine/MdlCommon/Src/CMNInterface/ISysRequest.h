#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <any>
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
		virtual std::any& GetData()const = 0;
	};
}