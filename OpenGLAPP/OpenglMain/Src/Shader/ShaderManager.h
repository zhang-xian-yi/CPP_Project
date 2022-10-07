#pragma once
#include <string>

namespace ShaderNS
{
	//ǰ������
	class ShaderManageGLPrivate;
	//��ɫ������
	class ShaderManager
	{
	public:
		//��ʼ����ɫ��
		int initShader();
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
		unsigned int GetuniformLocation(const std::string& name);
	private:
		ShaderNS::ShaderManageGLPrivate* _pShaderGLMag;
		unsigned int m_tmpShaderID;//��ɫ����ID
	};

}



