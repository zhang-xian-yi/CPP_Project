#pragma once
#include "MBean/LogSettingPara.h"

namespace Log4CppNS
{
	//日志的全局作用域
	class LoggerGlobal
	{
	public:
		static LoggerGlobal* GetInstance()
		{
			static LoggerGlobal instance;
			return &instance;
		}

	public:
		void DestoryInstance();
		void SetLogSetting(const LogSettingPara& setting);
		LogSettingPara& GetLogSetting();
	private:
		LoggerGlobal();
		~LoggerGlobal();
		LoggerGlobal(LoggerGlobal& instance);
		LoggerGlobal& operator=(const LoggerGlobal& instance);
	private:
		LogSettingPara m_logSetting;//日志设置参数
	};
}


