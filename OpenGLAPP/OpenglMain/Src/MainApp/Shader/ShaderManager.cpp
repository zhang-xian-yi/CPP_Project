#include "ShaderManager.h"
#include <iostream>
#include <string>
#include <fstream>//�ļ���
#include <sstream>//�ַ�����
#include <direct.h>
#include "ShaderManageGLPrivate.h"//ShaderManageGLPrivate ����
#include "GL/glew.h"

/// <summary>
/// ���캯��
/// </summary>
ShaderNS::ShaderManager::ShaderManager()
	:m_tmpShaderID(0)
{
	//��ʼ��ָ��
	_pShaderGLMag = new ShaderNS::ShaderManageGLPrivate();
}

/// <summary>
/// ��������
/// </summary>
ShaderNS::ShaderManager::~ShaderManager()
{
	UnBind();
	//ɾ����ɫ��
	glDeleteProgram(m_tmpShaderID);

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
int ShaderNS::ShaderManager::CreateShader(const std::string& vertexShaderStr, const std::string& fragmentShaderStr)
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

std::string ShaderNS::ShaderManager::ParseShaderFileRes(const std::string& filePath)
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


int ShaderNS::ShaderManager::initShader()
{
	//�����·������Ϊ�������·������ƫ�� direct.g �л�ȡ�������������·��
	std::string proPath = _getcwd(nullptr, 1);
	std::string VShaderStr = this->ParseShaderFileRes(proPath + "/Resource/Shaders/Vertex.shader");
	std::string FShaderStr = this->ParseShaderFileRes(proPath + "/Resource/Shaders/Fragment.shader");
	//����һ����ɫ��
	unsigned int shader = this->CreateShader(VShaderStr, FShaderStr);
	//���������
	m_tmpShaderID = shader;
	return 0;
}

void ShaderNS::ShaderManager::SetUniform1f(const std::string& name, int value)
{
	int location = GetuniformLocation(name);
	//����--location ������Ч
	if (location != -1)
	{
		//4f 4�������� Ҳ��Ӧvec4,�õ�ʵ��λ�ú���ʵ����ɫ����RGBA����
		glUniform1f(location,value);
	}
}

void ShaderNS::ShaderManager::SetUniform1f(const std::string& name, float value)
{
	int location = GetuniformLocation(name);
	//����--location ������Ч
	if (location != -1)
	{
		//4f 4�������� Ҳ��Ӧvec4,�õ�ʵ��λ�ú���ʵ����ɫ����RGBA����
		glUniform1f(location, value);
	}
}

/// <summary>
/// ���þ���
/// </summary>
/// <param name="name"></param>
/// <param name="proj"></param>
void ShaderNS::ShaderManager::SetUniformMatrix4f(const std::string& name,const glm::mat4& matrix)
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
		glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);

	}
}

void ShaderNS::ShaderManager::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	int location = GetuniformLocation(name);
	//����--location ������Ч
	if (location != -1)
	{
		//4f 4�������� Ҳ��Ӧvec4,�õ�ʵ��λ�ú���ʵ����ɫ����RGBA����
		glUniform4f(location, v0, v1, v2, v3);
	}
}

int ShaderNS::ShaderManager::GetuniformLocation(const std::string& name)
{
	int location =  glGetUniformLocation(m_tmpShaderID, name.c_str());
	if (location == -1)
	{
		std::cout << "warning uniform" << name << "not exist" << std::endl;
	}
	return location;
}

void ShaderNS::ShaderManager::Bind() const
{
	//ʹ�ô���ɫ��
	glUseProgram(m_tmpShaderID);
}

void ShaderNS::ShaderManager::UnBind() const
{
	glUseProgram(0);//ȡ����ɫ���İ�
}
