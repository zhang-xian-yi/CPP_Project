#pragma once
#include "ExportBean.h"

namespace Log4CppNS
{
	//日志的全局作用域
	class LoggerGlobal
	{
	public:
		static LoggerGlobal* GetInstancePointer()
		{
			static LoggerGlobal instance;
			return &instance;
		}

	public:	
		void SetLogSetting(const LogSettingPara& setting);
		const LogSettingPara* GetLogSetting()const;
	private:
		LoggerGlobal();
		~LoggerGlobal();
		LoggerGlobal(LoggerGlobal& instance) = delete;
		LoggerGlobal& operator=(const LoggerGlobal& instance) =delete;
	private:
		LogSettingPara* m_pLogSetting;//日志设置参数
	};
}


