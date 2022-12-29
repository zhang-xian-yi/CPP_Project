#pragma once
#include "ILModule.h"

namespace Log4CppNS
{
	class LModuleControl:public ILModule
	{
	public:
		//初始化日志模块
		LMStatus InitModule(LogSettingPara& para) override;
		//更新日志配置
		LMStatus UpdateSetting(LogSettingPara& para) override;
		//停止日志模块
		LMStatus StopModule() override;
		//获取模块状态
		bool IsUse() override;
	private:
		bool m_bIsUse;//模块是否可用
		bool m_bIsInit;//模块是否初始化
	};
}


