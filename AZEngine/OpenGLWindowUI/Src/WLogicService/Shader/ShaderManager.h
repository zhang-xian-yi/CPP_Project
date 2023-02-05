#pragma once
#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"// ͶӰ����
#include <unordered_map>//�������hash ��
//������������ 
namespace WindowsNS
{
	//ǰ������
	class ShaderManageGLPrivate;
	//��ɫ������
	class ShaderManager
	{
	public:
		//��ʼ����ɫ��
		int initShader(std::string VShaderStr, std::string FShaderStr);
		void SetUniform1f(const std::string& name, int value);
		void SetUniform1f(const std::string& name, float value);
		void SetUniform1iv(const std::string& name, int* iarr,int len);
		void SetUniformMatrix4f(const std::string& name, const glm::mat4& matrix);
		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void Bind()const;
		void UnBind()const;
		//��������������
		ShaderManager();
		~ShaderManager();
	private:
		//������ɫ�������ַ���������GPU��ɫ��
		int CreateShader(const std::string& vertexShaderStr, const std::string& fragmentShaderStr);
		//����GLSL���Ե���ɫ���ļ�
		std::string ParseShaderFileRes(const std::string& filePath);
		int GetuniformLocation(const std::string& name);
	private:
		ShaderManageGLPrivate* _pShaderGLMag;
		unsigned int m_tmpShaderID;//��ɫ����ID
		std::string m_VShaderPath;//������ɫ���ļ�
		std::string m_FShaderPath;//Ƭ����ɫ���ļ�
		//��¼��ɫ���е�uniform ��λ��
		std::unordered_map<std::string,int> m_uniformLocationCacheMap;
	};

}



