#pragma once
#include <string>
/*
隔离与openggl 相关的操作

*/

namespace ShaderNS
{
	/// <summary>
	/// 枚举着色器的类型
	/// </summary>
	enum  EShaderType
	{
		E_VertexShader_Type,
		E_FragmentShader_Type
	};

	class ShaderManageGLPrivate
	{
	public:
		//编译着色器
		unsigned int ComplieShaderGL(unsigned int type, const std::string& source);
		//构造函数
		ShaderManageGLPrivate();
	private:

	};
}

