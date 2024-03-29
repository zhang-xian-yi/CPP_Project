#include "WGLMacroDef.h"
#include <sstream>//字符串流
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "Logger/Src/ILogger.h"
#include "Glad/glad.h"

namespace WindowsNS
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
		//log 错误信息  这里的errir 是错误标记，
		std::stringstream ss;
		//这里是赋值 意思是将错误id复制给error变量， 并且判断error变量为0
		//while(0) 会跳出循环，含义为判断是否还存在错误信息
		while (GLenum error = glGetError())
		{
			ss<< "[OpenGL Error]: (" << error << ")" << "\n文件名:" << file
				<< "\n行数:" << line << "\n函数:" << func << "\n";
			//打印
			MdlCommonNS::LogMsgOSAsync(LoggerNS::ELogLevel::E_Error_LV,ss.str().c_str());
			//错误分支 
			return false;
		}
		//正确
		return true;
	}
}