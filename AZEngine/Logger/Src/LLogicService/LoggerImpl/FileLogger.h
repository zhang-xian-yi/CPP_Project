#pragma once
#include "LLogicService/BaseSpdlog.h"

namespace LoggerNS
{
	class FileLogger : public OptLogBase
	{
	private:
		std::string m_logPath;  // The log path which is specified in class constructor
	public:
		//���캯��
		FileLogger(const std::string& str);
		//�Զ��������Ŀ��
		virtual void AutoGenerateOutTarget()override;
		//��д
		virtual void CreateLogger() override;
	};
}