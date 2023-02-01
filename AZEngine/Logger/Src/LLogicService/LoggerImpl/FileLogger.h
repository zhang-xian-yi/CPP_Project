#pragma once
#include "LLogicService/BaseSpdlog.h"

namespace LoggerNS
{
	class FileLogger : public OptLogBase
	{
	private:
		std::string m_logPath;  // The log path which is specified in class constructor
	public:
		//构造函数
		FileLogger(const std::string& str);
		//自动生成输出目标
		virtual void AutoGenerateOutTarget()override;
		//重写
		virtual void CreateLogger() override;
	};
}