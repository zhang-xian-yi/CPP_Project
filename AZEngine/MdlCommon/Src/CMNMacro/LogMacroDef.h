#pragma once
#include "CMNExpMarcoDefine.h"
#include <string>

//前置声明
namespace LoggerNS
{
	enum class ELogLevel :unsigned char;
}

namespace MdlCommonNS
{
	/// <summary>
	/// 向日志标准输出和日志文件打印信息 
	/// </summary>
	/// <param name="msg"></param>
	/// <returns></returns>
	void MdlCommonDLLAPI LogMsgOSAsync(LoggerNS::ELogLevel logLv, const char* msg);

	template<typename... Args>
	std::string FormatMsg(Args &&... args)
	{
		return (... + args);
	}

	/// <summary>
	/// 日志打印函数
	/// </summary>
	/// <typeparam name="...Args"></typeparam>
	/// <param name="loglv"></param>
	/// <param name="...args"></param>
	template<typename... Args>
	void LogMsg(LoggerNS::ELogLevel loglv, Args &&... args)
	{
		auto str = FormatMsg(std::forward<Args>(args)...);
		//打印
		LogMsgOSAsync(loglv, str.c_str());
	}
}

