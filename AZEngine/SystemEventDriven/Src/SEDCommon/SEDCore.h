#pragma once
namespace SysEventDNS
{
//左移
#define LBit1(x) (1 << x)

		/// <summary>
	/// 向日志标准输出和日志文件打印信息 
	/// </summary>
	/// <param name="msg"></param>
	/// <returns></returns>
	void LogMsgOSAsync(const char* msg);


	template<class... T>
	void FormatLog(const char* fmt, const T&...t)
	{
		const auto len = snprintf(nullptr, 0, fmt, t...);
		std::string r;
		r.resize(static_cast<size_t>(len) + 1);
		snprintf(&r.front(), len + 1, fmt, t...);  // Bad boy
		r.resize(static_cast<size_t>(len));
		//日志输出
		LogMsgOSAsync(r.c_str());
	}
}