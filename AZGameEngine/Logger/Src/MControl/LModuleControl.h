#pragma once
#include "ILModule.h"

namespace Log4CppNS
{
	class LModuleControl:public ILModule
	{
	public:
		//初始化日志模块
		LMStatus InitModule(LogSettingPara& para) override;
		//停止日志模块
		LMStatus StopModule() override;
	};
}


