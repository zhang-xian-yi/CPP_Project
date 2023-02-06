#pragma once

#include <string>
namespace AZGameMainApp
{
	/// <summary>
	/// 向日志标准输出和日志文件打印信息 
	/// </summary>
	/// <param name="msg"></param>
	/// <returns></returns>
	void LogMsgOSAsync(const char* msg);

	template<typename... Args>
	std::string& FormatMsg(Args &&... args)
	{
		return (... + args);
	}

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
}