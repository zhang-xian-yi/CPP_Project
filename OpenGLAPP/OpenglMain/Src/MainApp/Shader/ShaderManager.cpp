#include "ShaderManager.h"
#include <iostream>
#include <string>
#include <fstream>//文件流
#include <sstream>//字符串流
#include <direct.h>
#include "ShaderManageGLPrivate.h"//ShaderManageGLPrivate 引入
#include "GL/glew.h"

/// <summary>
/// 构造函数
/// </summary>
ShaderNS::ShaderManager::ShaderManager()
	:m_tmpShaderID(0)
{
	//初始化指针
	_pShaderGLMag = new ShaderNS::ShaderManageGLPrivate();
}

/// <summary>
/// 析构函数
/// </summary>
ShaderNS::ShaderManager::~ShaderManager()
{
	UnBind();
	//删除着色器
	glDeleteProgram(m_tmpShaderID);

	if (_pShaderGLMag != nullptr)
	{
		delete _pShaderGLMag;
		_pShaderGLMag = nullptr;
	}
}

/// <summary>
/// 创建顶点着色器的业务
/// </summary>
/// <param name="vertexShader"></param>
/// <returns></returns>
int ShaderNS::ShaderManager::CreateShader(const std::string& vertexShaderStr, const std::string& fragmentShaderStr)
{
	//创建一个着色器程序
	unsigned int program = glCreateProgram();
	unsigned int vs = _pShaderGLMag->ComplieShaderGL(GL_VERTEX_SHADER, vertexShaderStr);
	unsigned int fs = _pShaderGLMag->ComplieShaderGL(GL_FRAGMENT_SHADER, fragmentShaderStr);

	//将着色器附加到程序中，注意一个程序可以有多个不同类型的着色器，当一种类型只需有一个
	//一个着色器是可以被附加到多个程序上
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	//如果程序中存在着色器 已经附加，那么就会连接(创建)一个该类型的片段/顶点着色器
	glLinkProgram(program);
	//检查程序中包含的可执行文件是否可以在当前的OpenGL状态下执行
	glValidateProgram(program);
	//释放内存与删除指定 shader 的 shader 对象
	//如果一个已附加到程序对象的 shader 对象被删除了，它的删除标记将会被设置，但它不会被删除，
	//直到该着色器附加的任意程序对象不再被附加。如果 shader 为0值，则会静默的忽略掉
	glDeleteShader(vs);
	//注意这种删除着色器的操作不是非常必要，其不会占据多少内存，且会影响过程信息输出
	glDeleteShader(fs);
	//返回程序ID
	return program;
}

std::string ShaderNS::ShaderManager::ParseShaderFileRes(const std::string& filePath)
{
	std::ifstream fileStream(filePath);
	//定义局部的字符串流变量
	std::stringstream resultStream;

	std::string line;//文件一行数据读取
	//将文件流中的数据读取为一行字符串
	while (std::getline(fileStream, line))
	{
		resultStream << line << "\n";
	}
	//返回字符串
	return resultStream.str();
}


int ShaderNS::ShaderManager::initShader()
{
	//这里的路径会因为工程相对路径进行偏移 direct.g 中获取解决方案下类库的路径
	std::string proPath = _getcwd(nullptr, 1);
	std::string VShaderStr = this->ParseShaderFileRes(proPath + "/Resource/Shaders/Vertex.shader");
	std::string FShaderStr = this->ParseShaderFileRes(proPath + "/Resource/Shaders/Fragment.shader");
	//创建一个着色器
	unsigned int shader = this->CreateShader(VShaderStr, FShaderStr);
	//复制类变量
	m_tmpShaderID = shader;
	return 0;
}

void ShaderNS::ShaderManager::SetUniform1f(const std::string& name, int value)
{
	int location = GetuniformLocation(name);
	//断言--location 必须有效
	if (location != -1)
	{
		//4f 4个浮点数 也对应vec4,得到实际位置后，向实际颜色发送RGBA数据
		glUniform1f(location,value);
	}
}

void ShaderNS::ShaderManager::SetUniform1f(const std::string& name, float value)
{
	int location = GetuniformLocation(name);
	//断言--location 必须有效
	if (location != -1)
	{
		//4f 4个浮点数 也对应vec4,得到实际位置后，向实际颜色发送RGBA数据
		glUniform1f(location, value);
	}
}

/// <summary>
/// 设置矩阵
/// </summary>
/// <param name="name"></param>
/// <param name="proj"></param>
void ShaderNS::ShaderManager::SetUniformMatrix4f(const std::string& name,const glm::mat4& matrix)
{
	//这里的矩阵设置可以是一次，但是如果是一次设置一直有效的化，就没必要想颜色的unifomr
	//一样每次刷新都设置一次，这种限制图片纵横比的的矩阵只需要设置一次
	int location = GetuniformLocation(name);
	if (location != -1)
	{
		// 用4个float 形成的matrix
		//1 表示矩阵为1个
		//GL_FALSE 矩阵为列主， 如果是行主需要转置，OpenGL希望得到列主的矩阵
		// &matrix[0][0] 矩阵的内存地址也可以是矩阵第0行第0列的地址
		glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);

	}
}

void ShaderNS::ShaderManager::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	int location = GetuniformLocation(name);
	//断言--location 必须有效
	if (location != -1)
	{
		//4f 4个浮点数 也对应vec4,得到实际位置后，向实际颜色发送RGBA数据
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
	//使用此着色器
	glUseProgram(m_tmpShaderID);
}

void ShaderNS::ShaderManager::UnBind() const
{
	glUseProgram(0);//取消着色器的绑定
}
