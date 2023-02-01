#pragma once
#include <string>
namespace LoggerNS
{
	enum class ELogLevel:unsigned char
	{
		E_Trace_LV,//����
		E_Debug_LV,//����
		E_Info_LV,//��Ϣ
		E_Warn_LV,//��Ϣ
		E_Error_LV,//����
		E_Critical_LV,//������Ҫ
	};

	/// <summary>
	/// ������־�ӿ�
	/// </summary>
	class IFileLogger
	{
	public:
		virtual void LogFileMsg(ELogLevel logLv,const std::string&& msg) = 0;
	};

	/// <summary>
	/// ��׼����ӿ�
	/// </summary>
	class IStdoutLogger
	{
	public:
		virtual void LogStdoutMsg(ELogLevel logLv, const std::string&& msg) = 0;
	};
}