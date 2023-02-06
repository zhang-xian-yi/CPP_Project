#pragma once
namespace LoggerNS
{
	enum class ELogLevel :unsigned char;
}

#include <string>
namespace SysEventDNS
{
//左移
#define LBit1(x) (1 << x)

		/// <summary>
	/// 向日志标准输出和日志文件打印信息 
	/// </summary>
	/// <param name="msg"></param>
	/// <returns></returns>
	void LogMsgOSAsync(LoggerNS::ELogLevel logLv,const char* msg);


	template<typename... Args>
	std::string FormatMsg(Args &&... args)
	{
		return (... + args);
	}

	template<typename... Args>
	void LogMsg(LoggerNS::ELogLevel loglv, Args &&... args)
	{
		auto str = FormatMsg(std::forward<Args>(args)...);
		//打印
		LogMsgOSAsync(loglv, str.c_str());
	}
}