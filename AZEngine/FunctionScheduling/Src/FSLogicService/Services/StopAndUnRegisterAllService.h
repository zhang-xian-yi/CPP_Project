#pragma once
#include "FSLogicService/IService.h"

namespace FuncScheduleNS
{
	/// <summary>
	/// ��ʼ���Լ�ע�����й���ģ���ҵ���߼�
	/// </summary>
	class StopAndUnRegisterAllService :public ICmdService
	{
	public:
		StopAndUnRegisterAllService() = default;
		virtual ~StopAndUnRegisterAllService() = default;
	public:
		//ִ��ҵ���߼���ں���
		virtual void DoService();
	};
}

