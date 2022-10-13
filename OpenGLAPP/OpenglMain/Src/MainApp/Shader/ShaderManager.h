#pragma once
#include <string>

namespace ShaderNS
{
	//前置声明
	class ShaderManageGLPrivate;
	//着色器管理
	class ShaderManager
	{
	public:
		//初始化着色器
		int initShader();
		void SetUniform1f(const std::string& name, int value);
		void SetUniform1f(const std::string& name, float value);
		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void Bind()const;
		void UnBind()const;
		//构造与析构函数
		ShaderManager();
		~ShaderManager();
	private:
		//根据着色器程序字符串，创建GPU着色器
		int CreateShader(const std::string& vertexShaderStr, const std::string& fragmentShaderStr);
		//解析GLSL语言的着色器文件
		std::string ParseShaderFileRes(const std::string& filePath);
		int GetuniformLocation(const std::string& name);
	private:
		ShaderNS::ShaderManageGLPrivate* _pShaderGLMag;
		unsigned int m_tmpShaderID;//着色器的ID
	};

}



