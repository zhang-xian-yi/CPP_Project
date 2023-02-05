#include "ShaderManageGLPrivate.h"
#include <iostream>
#include "GL/glew.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"//错误检查

namespace WindowsNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	ShaderManageGLPrivate::ShaderManageGLPrivate()
	{

	}

	unsigned int ShaderManageGLPrivate::ComplieShaderGL(unsigned int type, const std::string& source)
	{
		//glCreateShader创建一个空的着色器对象，并返回一个可以引用的非零值（shader ID）。
		//着色器对象用于维护定义着色器的源代码字符串。shaderType指示要创建的着色器的类型
		unsigned int id = glCreateShader(type);
		//c_str() 返回内部有效字符串的首地址，注意内部字符串必须存在，如果使用getString()的方式
		//获取的临时字符串可能超出作用域得到的指针会是空
		const char* src = source.c_str();
		//
		/* glShaderSource将着色器中的源代码设置为string指定的字符串数组中的源代码。
		先前存储在着色器对象中的任何源代码都将被完全替换
		shader:要被替换源代码的着色器对象的句柄（ID）。
		count:指定字符串和长度数组中的元素数。
		string:指定指向包含要加载到着色器的源代码的字符串的指针数组。
		length:指定字符串长度的数组。*/
		GLCallWarn(glShaderSource(id, 1, &src, nullptr));
		//glCompileShader编译已存储在shader指定的着色器对象中的源代码字符串
		//GL_TRUE OR GL_FALSE
		GLCallWarn(glCompileShader(id));

		//TODO error handing
		int result;
		//从着色器中获取一个参数，此处作用时检测着色器是否编译成功，GL_TRUE OR GL_FALSE
		GLCallWarn(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
		//结果错误
		if (!result)
		{
			int logLength;
			GLCallWarn(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength));
			//从栈区上灵活分配内存，且超出作用域后自动释放
			char* message = (char*)alloca(logLength * sizeof(char));
			//将错误信息刷入缓存区
			GLCallWarn(glGetShaderInfoLog(id, logLength, &logLength, message));
			//输出着色器数据
			std::cout << "编译" << (type == GL_VERTEX_SHADER ? "顶点" : "片段") << "着色器失败" << std::endl;
			std::cout << "Message: " << message << std::endl;

			GLCallWarn(glDeleteShader(id));//删除着色器
			//返回值时 unsign int 所以不能返回-1  
			return 0;
		}
		//返回 id
		return id;
	}
}
