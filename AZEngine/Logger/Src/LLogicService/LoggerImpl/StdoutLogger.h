#pragma once
#include "LLogicService/BaseSpdlog.h"

namespace LoggerNS
{
	class StdoutLogger : public OptLogBase
	{
	public:
		//对于控制台子类来说，无需生成file文件，因此该方法的函数体置空
		virtual void AutoGenerateOutTarget()override;
		//
		virtual void CreateLogger()override;
	};
}