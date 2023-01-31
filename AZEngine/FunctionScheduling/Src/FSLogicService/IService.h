#pragma once
#include <memory>//unique_ptr ����

namespace MdlCommonNS
{
	//ǰ������
	enum class EModuleType :unsigned char;
	class IMdlFactory;
}

namespace FuncScheduleNS
{
	/*
	ʵ�ִ�Iservice �ӿڵ����࣬ÿ���������Ӧָ����������
	����������MdlCommonģ��� ECommand ��ö�������ά��
	ECommand������ʵ���Ĺ�ϵ ��FuncScheduleCtlPrivate�����map��ʽ��ά��
	*/

	class ICmdService
	{
	public:
		virtual ~ICmdService() = 0;
	public:
		//ִ��ҵ���߼���ں���
		virtual void DoService() = 0;
	};

}