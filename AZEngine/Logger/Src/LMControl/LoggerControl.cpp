#include "LoggerControl.h"
#include "LLogicService/LoggerManager.h"//��־����

namespace LoggerNS
{
	LoggerControl::LoggerControl()
	{
	}
	LoggerControl::~LoggerControl()
	{
	}
	/// <summary>
	/// ��ӡ����ʱ����־
	/// </summary>
	/// <param name="logLv"></param>
	/// <param name="msg"></param>
	void LoggerControl::LogFileMsg(ELogLevel logLv, const std::string&& msg)
	{
		switch (logLv)
		{
		case LoggerNS::ELogLevel::E_Trace_LV:
			Run_Log_Trace(msg);
			break;
		case LoggerNS::ELogLevel::E_Debug_LV:
			Run_Log_Debug(msg);
			break;
		case LoggerNS::ELogLevel::E_Info_LV:
			Run_Log_Info(msg);
			break;
		case LoggerNS::ELogLevel::E_Warn_LV:
			Run_Log_Warn(msg);
			break;
		case LoggerNS::ELogLevel::E_Error_LV:
			Run_Log_Error(msg);
			break;
		case LoggerNS::ELogLevel::E_Critical_LV:
			break;
			Run_Log_Critical(msg);
		default:
			break;
		}

	}

	/// <summary>
	/// ��ӡ��׼�����־
	/// </summary>
	/// <param name="logLv"></param>
	/// <param name="msg"></param>
	void LoggerControl::LogStdoutMsg(ELogLevel logLv, const std::string&& msg)
	{
		switch (logLv)
		{
		case LoggerNS::ELogLevel::E_Trace_LV:
			Stdout_Log_Trace(msg);
			break;
		case LoggerNS::ELogLevel::E_Debug_LV:
			Stdout_Log_Debug(msg);
			break;
		case LoggerNS::ELogLevel::E_Info_LV:
			Stdout_Log_Info(msg);
			break;
		case LoggerNS::ELogLevel::E_Warn_LV:
			Stdout_Log_Warn(msg);
			break;
		case LoggerNS::ELogLevel::E_Error_LV:
			Stdout_Log_Error(msg);
			break;
		case LoggerNS::ELogLevel::E_Critical_LV:
			break;
			Stdout_Log_Critical(msg);
		default:
			break;
		}
	}
}