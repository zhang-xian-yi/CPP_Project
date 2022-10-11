#ifndef ErrorMacroDefie_H
#define ErrorMacroDefie_H

#include "GL/glew.h"
#include <GLFW/glfw3.h>
#include <iostream>
//�˴�ͷ�ļ�����꺯�� �� ��������
namespace ErrorNS
{
	/// <summary>
	/// ���
	/// </summary>
	void GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	/// <summary>
	/// ��ӡ��־�еĴ�����Ϣ
	/// </summary>
	/// <param name="file">const char* ��C++���ú궨������ͣ������ļ���</param>
	/// <param name="line">�ļ���</param>
	/// <param name="func">�ַ���</param>
	/// <returns></returns>
	bool GLLogError(const char* file, int line, const char* func)
	{
		//�����Ǹ�ֵ ��˼�ǽ�����id���Ƹ�error������ �����ж�error����Ϊ0
		//while(0) ������ѭ��������Ϊ�ж��Ƿ񻹴��ڴ�����Ϣ
		while (GLenum error = glGetError())
		{
			//log ������Ϣ  �����errir �Ǵ����ǣ�
			std::cout << "[opengl error]: (" << error << ")" << "\n�ļ���:" << file
				<< "\n����:" << line << "\n����:" << func << std::endl;
			//�����֧ 
			return false;
		}
		//��ȷ
		return true;
	}

//ע��debugbreak() ��һ�������жϵĺ���
//�ú궨����ζ��һ������xΪfalse �����������ж�
//ֻ��MSVC�д��ڣ� ��������CLang����GCC��
#define MacroDefAssert(x) if(!(x)) __debugbreak();

//ͨ�����滻�ķ�ʽ��X����ִ�й����滻Ϊ���κ���ִ�еĹ���
//���������⣬������־��Ϣ��ӡ�ȡ������ж�
//ע��#x ���Խ�X����ת��Ϊ�ַ���
#define GLCallWarn(x) ErrorNS::GLClearError();\
					  x;\
					  MacroDefAssert(ErrorNS::GLLogError(__FILE__,__LINE__,#x))
}

#endif // ErrorMacroDefie_H



