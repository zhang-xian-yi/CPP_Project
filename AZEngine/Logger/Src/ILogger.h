#pragma once
#include <string>
namespace LoggerNS
{
	enum class ELogLevel:unsigned char
	{
		E_Trace_LV,//跟踪
		E_Debug_LV,//调试
		E_Info_LV,//信息
		E_Warn_LV,//信息
		E_Error_LV,//错误
		E_Critical_LV,//至关重要
	};

	/// <summary>
	/// 运行日志接口
	/// </summary>
	class IFileLogger
	{
	public:
		virtual void LogFileMsg(ELogLevel logLv,const std::string&& msg) = 0;
	};

	/// <summary>
	/// 标准输出接口
	/// </summary>
	class IStdoutLogger
	{
	public:
		virtual void LogStdoutMsg(ELogLevel logLv, const std::string&& msg) = 0;
	};
}