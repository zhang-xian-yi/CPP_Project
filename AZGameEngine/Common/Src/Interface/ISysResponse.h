#pragma once
#include <Common/ExportMarcoDefine.h> //������


namespace CommonNS
{
	//ϵͳ������Ӧ
	class ISysResponse
	{
	public:
		//Լ�����е�ϵͳ��Ӧ���ݱ���ʵ�ִ˷���
		virtual bool IsValid() const = 0;
	};
}