#pragma once
#include "Common/MarcoDefine.h"

namespace Log4CppNS
{
	//前置声明 枚举
	enum class LMStatus :unsigned char;

	//日志模块设置参数 前置声明
	struct LogSettingPara;


	//日志模块的模块
	class LogerAPI ILModule
	{
	public:
		//初始化日志模块
		virtual LMStatus InitModule(LogSettingPara& para) = 0;
		//更新日志配置模块
		virtual LMStatus UpdateSetting(LogSettingPara& para) = 0;
		//停止日志模块
		virtual LMStatus StopModule() = 0;
		//获取模块状态
		virtual bool IsUse() = 0;
	};
}