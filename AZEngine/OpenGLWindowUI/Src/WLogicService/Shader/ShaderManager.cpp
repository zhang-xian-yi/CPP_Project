#include "ShaderManager.h"
#include <iostream>
#include <string>
#include <fstream>//�ļ���
#include <sstream>//�ַ�����
#include <direct.h>
#include "ShaderManageGLPrivate.h"//ShaderManageGLPrivate ����
#include "Glad/glad.h"
#include "WCommon/WGLMacroDef.h"//������
namespace ImguiRendererNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	ShaderManager::ShaderManager()
		:m_tmpShaderID(0)
	{
		//��ʼ��ָ��
		_pShaderGLMag = new ShaderManageGLPrivate();
	}

	/// <summary>
	/// ��������
	/// </summary>
	ShaderManager::~ShaderManager()
	{
		UnBind();
		//ɾ����ɫ��
		GLCallWarn(glDeleteProgram(m_tmpShaderID));

		if (_pShaderGLMag != nullptr)
		{
			delete _pShaderGLMag;
			_pShaderGLMag = nullptr;
		}
	}

	/// <summary>
	/// ����������ɫ����ҵ��
	/// </summary>
	/// <param name="vertexShader"></param>
	/// <returns></returns>
	int ShaderManager::CreateShader(const std::string& vertexShaderStr, const std::string& fragmentShaderStr)
	{
		//����һ����ɫ������
		unsigned int program = glCreateProgram();
		unsigned int vs = _pShaderGLMag->ComplieShaderGL(GL_VERTEX_SHADER, vertexShaderStr);
		unsigned int fs = _pShaderGLMag->ComplieShaderGL(GL_FRAGMENT_SHADER, fragmentShaderStr);

		//����ɫ�����ӵ������У�ע��һ����������ж����ͬ���͵���ɫ������һ������ֻ����һ��
		//һ����ɫ���ǿ��Ա����ӵ����������
		glAttachShader(program, vs);
		glAttachShader(program, fs);
		//��������д�����ɫ�� �Ѿ����ӣ���ô�ͻ�����(����)һ�������͵�Ƭ��/������ɫ��
		glLinkProgram(program);
		//�������а����Ŀ�ִ���ļ��Ƿ�����ڵ�ǰ��OpenGL״̬��ִ��
		glValidateProgram(program);
		//�ͷ��ڴ���ɾ��ָ�� shader �� shader ����
		//���һ���Ѹ��ӵ��������� shader ����ɾ���ˣ�����ɾ����ǽ��ᱻ���ã��������ᱻɾ����
		//ֱ������ɫ�����ӵ������������ٱ����ӡ���� shader Ϊ0ֵ����ᾲĬ�ĺ��Ե�
		glDeleteShader(vs);
		//ע������ɾ����ɫ���Ĳ������Ƿǳ���Ҫ���䲻��ռ�ݶ����ڴ棬�һ�Ӱ�������Ϣ���
		glDeleteShader(fs);
		//���س���ID
		return program;
	}

	std::string ShaderManager::ParseShaderFileRes(const std::string& filePath)
	{
		std::ifstream fileStream(filePath);
		//����ֲ����ַ���������
		std::stringstream resultStream;

		std::string line;//�ļ�һ�����ݶ�ȡ
		//���ļ����е����ݶ�ȡΪһ���ַ���
		while (std::getline(fileStream, line))
		{
			resultStream << line << "\n";
		}
		//�����ַ���
		return resultStream.str();
	}


	int ShaderManager::initShader(std::string VTmpShader, std::string FTmpShader)
	{
		//�����·������Ϊ�������·������ƫ�� direct.g �л�ȡ�������������·��
		std::string proPath = _getcwd(nullptr, 1);
		m_VShaderPath = this->ParseShaderFileRes(proPath + VTmpShader);
		m_FShaderPath = this->ParseShaderFileRes(proPath + FTmpShader);
		//����һ����ɫ��
		unsigned int shader = this->CreateShader(m_VShaderPath, m_FShaderPath);
		//���������
		m_tmpShaderID = shader;
		return 0;
	}

	void ShaderManager::SetUniform1f(const std::string& name, int value)
	{
		int location = GetuniformLocation(name);
		//����--location ������Ч
		if (location != -1)
		{
			//4f 4�������� Ҳ��Ӧvec4,�õ�ʵ��λ�ú���ʵ����ɫ����RGBA����
			glUniform1f(location, value);
		}
	}

	void ShaderManager::SetUniform1f(const std::string& name, float value)
	{
		int location = GetuniformLocation(name);
		//����--location ������Ч
		if (location != -1)
		{
			//4f 4�������� Ҳ��Ӧvec4,�õ�ʵ��λ�ú���ʵ����ɫ����RGBA����
			glUniform1f(location, value);
		}
	}

	void ShaderManager::SetUniform1iv(const std::string& name, int* iarr, int len)
	{
		int location = GetuniformLocation(name);
		//����--location ������Ч
		if (location != -1)
		{
			//4f 4�������� Ҳ��Ӧvec4,�õ�ʵ��λ�ú���ʵ����ɫ����RGBA����
			glUniform1iv(location, len, iarr);
		}
	}

	/// <summary>
	/// ���þ���
	/// </summary>
	/// <param name="name"></param>
	/// <param name="proj"></param>
	void ShaderManager::SetUniformMatrix4f(const std::string& name, const glm::mat4& matrix)
	{
		//����ľ������ÿ�����һ�Σ����������һ������һֱ��Ч�Ļ�����û��Ҫ����ɫ��unifomr
		//һ��ÿ��ˢ�¶�����һ�Σ���������ͼƬ�ݺ�ȵĵľ���ֻ��Ҫ����һ��
		int location = GetuniformLocation(name);
		if (location != -1)
		{
			// ��4��float �γɵ�matrix
			//1 ��ʾ����Ϊ1��
			//GL_FALSE ����Ϊ������ �����������Ҫת�ã�OpenGLϣ���õ������ľ���
			// &matrix[0][0] ������ڴ��ַҲ�����Ǿ����0�е�0�еĵ�ַ
			GLCallWarn(glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]));

		}
	}

	void ShaderManager::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
	{
		int location = GetuniformLocation(name);
		//����--location ������Ч
		if (location != -1)
		{
			//4f 4�������� Ҳ��Ӧvec4,�õ�ʵ��λ�ú���ʵ����ɫ����RGBA����
			GLCallWarn(glUniform4f(location, v0, v1, v2, v3));
		}
	}

	int ShaderManager::GetuniformLocation(const std::string& name)
	{
		//��������ڵ���ɫ������
		if (m_uniformLocationCacheMap.find(name) != m_uniformLocationCacheMap.end())
		{
			//�����ҵ���uniform ֵ
			return m_uniformLocationCacheMap[name];
		}
		//δ�ҵ�ָ����unifrom ֵ ͨ����ѯopengl������ȡ
		int location = glGetUniformLocation(m_tmpShaderID, name.c_str());
		if (location != -1)
		{
			//����ָ����name ��uniform ��location
			m_uniformLocationCacheMap[name] = location;
		}
		else
		{
			std::cout << "warning uniform" << name << "not exist" << std::endl;
		}
		return location;
	}

	void ShaderManager::Bind() const
	{
		//ʹ�ô���ɫ��
		GLCallWarn(glUseProgram(m_tmpShaderID));
	}

	void ShaderManager::UnBind() const
	{
		GLCallWarn(glUseProgram(0));//ȡ����ɫ���İ�
	}

}
