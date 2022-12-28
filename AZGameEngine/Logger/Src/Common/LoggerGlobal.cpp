#include "LoggerGlobal.h"
namespace Log4CppNS
{
	void LoggerGlobal::DestoryInstance()
	{

	}

	void LoggerGlobal::SetLogSetting(const LogSettingPara& setting)
	{
		m_logSetting = setting;
	}

	LogSettingPara& LoggerGlobal::GetLogSetting()
	{
		// TODO: 在此处插入 return 语句
		return m_logSetting;
	}

#pragma region 私有 不允许外部嗲用

	LoggerGlobal::LoggerGlobal()
	{
	}
	LoggerGlobal::~LoggerGlobal()
	{
	}
	LoggerGlobal::LoggerGlobal(LoggerGlobal& instance)
	{
	}
#pragma endregion
}