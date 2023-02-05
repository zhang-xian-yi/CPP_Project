#pragma once
/*
注意 这里的CPP文件为了解决多次定义行数的问题，
这里的全局函数均是声明，多次声明，一次实现，就能解决反复定义的问题

*/

#include <string>
namespace WindowsNS
{
	/// <summary>
	/// 检测
	/// </summary>
	void GLClearError();

	/// <summary>
	/// 打印日志中的错误信息
	/// </summary>
	/// <param name="file">const char* 是C++内置宏定义的类型，描述文件名</param>
	/// <param name="line">文件行</param>
	/// <param name="func">字符串</param>
	/// <returns></returns>
	bool GLLogError(const char* file, int line, const char* func);

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




//注意debugbreak() 是一个调试中断的函数
//该宏定义意味着一旦出现x为false 则启动调试中断
//只在MSVC中存在， 不出现在CLang或者GCC中
#define MacroDefAssert(x) if(!(x)) __debugbreak();

//通过宏替换的方式将X函数执行过程替换为三段函数执行的过程
//包括错误检测，错误日志信息打印等。并且中断
//注意#x 可以将X函数转换为字符串
#define GLCallWarn(x) WindowsNS::GLClearError();\
					  x;\
					  MacroDefAssert(WindowsNS::GLLogError(__FILE__,__LINE__,#x))


