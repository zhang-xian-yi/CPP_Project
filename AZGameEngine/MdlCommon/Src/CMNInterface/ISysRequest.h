#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������

namespace MdlCommonNS
{
	//ϵͳ��������
	class MdlCommonDLLAPI ISysRequest
	{
	public:
		virtual ~ISysRequest() = 0;
	public:
		//Լ�����е�ϵͳ�������ݱ���ʵ�ִ˷���
		virtual bool IsValid()const = 0;
	};
}