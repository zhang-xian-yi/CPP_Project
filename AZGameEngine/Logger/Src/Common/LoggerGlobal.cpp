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
		// TODO: �ڴ˴����� return ���
		return m_logSetting;
	}

#pragma region ˽�� �������ⲿ����

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