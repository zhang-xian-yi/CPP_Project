#pragma once
#include <Common/ExportMarcoDefine.h> //������

namespace CommonNS
{
	//ϵͳ��������
	class ISysRequest
	{
	public:
		//Լ�����е�ϵͳ�������ݱ���ʵ�ִ˷���
		virtual bool IsValid()const = 0;
	};
}