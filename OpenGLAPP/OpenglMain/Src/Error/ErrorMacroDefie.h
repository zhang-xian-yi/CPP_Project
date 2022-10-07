#ifndef ErrorMacroDefie_H
#define ErrorMacroDefie_H

#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include <iostream>
//此处头文件定义宏函数 和 错误处理方案
namespace ErrorNS
{
	/// <summary>
	/// 检测
	/// </summary>
	void GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	/// <summary>
	/// 打印日志中的错误信息
	/// </summary>
	/// <param name="file">const char* 是C++内置宏定义的类型，描述文件名</param>
	/// <param name="line">文件行</param>
	/// <param name="func">字符串</param>
	/// <returns></returns>
	bool GLLogError(const char* file, int line, const char* func)
	{
		//这里是赋值 意思是将错误id复制给error变量， 并且判断error变量为0
		//while(0) 会跳出循环，含义为判断是否还存在错误信息
		while (GLenum error = glGetError())
		{
			//log 错误信息  这里的errir 是错误标记，
			std::cout << "[opengl error]: (" << error << ")" << "\n文件名:" << file
				<< "\n行数:" << line << "\n函数:" << func << std::endl;
			//错误分支 
			return false;
		}
		//正确
		return true;
	}

//注意debugbreak() 是一个调试中断的函数
//该宏定义意味着一旦出现x为false 则启动调试中断
//只在MSVC中存在， 不出现在CLang或者GCC中
#define MacroDefAssert(x) if(!(x)) __debugbreak();

//通过宏替换的方式将X函数执行过程替换为三段函数执行的过程
//包括错误检测，错误日志信息打印等。并且中断
//注意#x 可以将X函数转换为字符串
#define GLCallWarn(x) ErrorNS::GLClearError();\
					  x;\
					  MacroDefAssert(ErrorNS::GLLogError(__FILE__,__LINE__,#x))
}

#endif // ErrorMacroDefie_H



