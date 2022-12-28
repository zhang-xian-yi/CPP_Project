#pragma once

namespace Log4CppNS
{
	//前置声明 枚举
	enum class LMStatus :unsigned char;

	//日志模块设置参数 前置声明
	struct LogSettingPara;


	//日志模块的模块
	class ILModule
	{
	public:
		//初始化日志模块
		virtual LMStatus InitModule(LogSettingPara& para) = 0;
		//停止日志模块
		virtual LMStatus StopModule() = 0;
	private:
		bool m_bIsUse;//模块是否可用
		bool m_bIsInit;//模块是否初始化
	};
}