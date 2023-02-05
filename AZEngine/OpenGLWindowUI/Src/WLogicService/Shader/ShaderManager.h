#pragma once
#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"// 投影矩阵
#include <unordered_map>//非排序的hash 表
//声明第三方库 
namespace WindowsNS
{
	//前置声明
	class ShaderManageGLPrivate;
	//着色器管理
	class ShaderManager
	{
	public:
		//初始化着色器
		int initShader(std::string VShaderStr, std::string FShaderStr);
		void SetUniform1f(const std::string& name, int value);
		void SetUniform1f(const std::string& name, float value);
		void SetUniform1iv(const std::string& name, int* iarr,int len);
		void SetUniformMatrix4f(const std::string& name, const glm::mat4& matrix);
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
		ShaderManageGLPrivate* _pShaderGLMag;
		unsigned int m_tmpShaderID;//着色器的ID
		std::string m_VShaderPath;//顶点着色器文件
		std::string m_FShaderPath;//片段着色器文件
		//记录着色器中的uniform 的位置
		std::unordered_map<std::string,int> m_uniformLocationCacheMap;
	};

}



