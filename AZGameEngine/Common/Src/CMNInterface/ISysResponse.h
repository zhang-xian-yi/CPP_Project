#pragma once
#include <CMNCommon/CMNExpMarcoDefine.h> //������


namespace CommonNS
{
	//ϵͳ������Ӧ
	class CommonDLLAPI ISysResponse
	{
	public:
		virtual ~ISysResponse() = 0;
	public:
		//Լ�����е�ϵͳ��Ӧ���ݱ���ʵ�ִ˷���
		virtual bool IsValid() const = 0;
	};
}