#pragma once
#include "LLogicService/BaseSpdlog.h"

namespace LoggerNS
{
	class StdoutLogger : public OptLogBase
	{
	public:
		//���ڿ���̨������˵����������file�ļ�����˸÷����ĺ������ÿ�
		virtual void AutoGenerateOutTarget()override;
		//
		virtual void CreateLogger()override;
	};
}