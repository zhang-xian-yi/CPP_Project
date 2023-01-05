#include "LoggerGlobal.h"
#include "ExportBean.h"
namespace Log4CppNS
{
	void LoggerGlobal::SetLogSetting(const LogSettingPara& setting)
	{
		m_pLogSetting = new Log4CppNS::LogSettingPara();
		m_pLogSetting->logLevel = setting.logLevel;
		m_pLogSetting->logTarget = setting.logTarget;

	}

	const LogSettingPara* LoggerGlobal::GetLogSetting()const
	{
		// TODO: 在此处插入 return 语句
		return m_pLogSetting;
	}

#pragma region 私有 不允许外部嗲用

	LoggerGlobal::LoggerGlobal()
	{
	}
	LoggerGlobal::~LoggerGlobal()
	{
	}
#pragma endregion
}