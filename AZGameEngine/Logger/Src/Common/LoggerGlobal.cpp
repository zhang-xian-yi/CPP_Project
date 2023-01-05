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
		// TODO: �ڴ˴����� return ���
		return m_pLogSetting;
	}

#pragma region ˽�� �������ⲿ����

	LoggerGlobal::LoggerGlobal()
	{
	}
	LoggerGlobal::~LoggerGlobal()
	{
	}
#pragma endregion
}