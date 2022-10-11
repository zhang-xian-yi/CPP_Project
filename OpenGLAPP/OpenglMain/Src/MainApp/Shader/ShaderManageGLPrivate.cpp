#include "ShaderManageGLPrivate.h"
#include <iostream>
#include "GL/glew.h"
/// <summary>
/// ���캯��
/// </summary>
ShaderNS::ShaderManageGLPrivate::ShaderManageGLPrivate()
{

}

unsigned int ShaderNS::ShaderManageGLPrivate::ComplieShaderGL(unsigned int type, const std::string& source)
{
	//glCreateShader����һ���յ���ɫ�����󣬲�����һ���������õķ���ֵ��shader ID����
	//��ɫ����������ά��������ɫ����Դ�����ַ�����shaderTypeָʾҪ��������ɫ��������
	unsigned int id = glCreateShader(type);
	//c_str() �����ڲ���Ч�ַ������׵�ַ��ע���ڲ��ַ���������ڣ����ʹ��getString()�ķ�ʽ
	//��ȡ����ʱ�ַ������ܳ���������õ���ָ����ǿ�
	const char* src = source.c_str();
	//
	/* glShaderSource����ɫ���е�Դ��������Ϊstringָ�����ַ��������е�Դ���롣
	��ǰ�洢����ɫ�������е��κ�Դ���붼������ȫ�滻
	shader:Ҫ���滻Դ�������ɫ������ľ����ID����
	count:ָ���ַ����ͳ��������е�Ԫ������
	string:ָ��ָ�����Ҫ���ص���ɫ����Դ������ַ�����ָ�����顣
	length:ָ���ַ������ȵ����顣*/
	glShaderSource(id, 1, &src, nullptr);
	//glCompileShader�����Ѵ洢��shaderָ������ɫ�������е�Դ�����ַ���
	//GL_TRUE OR GL_FALSE
	glCompileShader(id);

	//TODO error handing
	int result;
	//����ɫ���л�ȡһ���������˴�����ʱ�����ɫ���Ƿ����ɹ���GL_TRUE OR GL_FALSE
	glGetShaderiv(id,GL_COMPILE_STATUS,&result);
	//�������
	if (!result)
	{
		int logLength;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength);
		//��ջ�����������ڴ棬�ҳ�����������Զ��ͷ�
		char* message = (char*)alloca(logLength * sizeof(char));
		//��������Ϣˢ�뻺����
		glGetShaderInfoLog(id, logLength, &logLength, message);
		//�����ɫ������
		std::cout << "����" << (type == GL_VERTEX_SHADER ? "����" : "Ƭ��") << "��ɫ��ʧ��" << std::endl;
		std::cout <<"Message: " << message << std::endl;
		
		glDeleteShader(id);//ɾ����ɫ��
		//����ֵʱ unsign int ���Բ��ܷ���-1  
		return 0;
	}
	//���� id
	return id;
}