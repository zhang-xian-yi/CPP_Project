#pragma once
#include "MBean/LogSettingPara.h"

namespace Log4CppNS
{
	//��־��ȫ��������
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
		LogSettingPara& GetLogSetting();
	private:
		LoggerGlobal();
		~LoggerGlobal();
		LoggerGlobal(LoggerGlobal& instance) = delete;
		LoggerGlobal& operator=(const LoggerGlobal& instance) =delete;
	private:
		LogSettingPara m_logSetting;//��־���ò���
	};
}


