#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������


namespace MdlCommonNS
{
	//ϵͳ������Ӧ
	class MdlCommonDLLAPI ISysResponse
	{
	public:
		virtual ~ISysResponse() = 0;
	public:
		//Լ�����е�ϵͳ��Ӧ���ݱ���ʵ�ִ˷���
		virtual bool IsValid() const = 0;
	};
}