#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������

namespace CommonNS
{
	//ϵͳ��������
	class CommonDLLAPI ISysRequest
	{
	public:
		virtual ~ISysRequest() = 0;
	public:
		//Լ�����е�ϵͳ�������ݱ���ʵ�ִ˷���
		virtual bool IsValid()const = 0;
	};
}