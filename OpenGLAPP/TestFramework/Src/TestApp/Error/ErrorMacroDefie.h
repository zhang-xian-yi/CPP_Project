#pragma once
/*
ע�� �����CPP�ļ�Ϊ�˽����ζ������������⣬
�����ȫ�ֺ����������������������һ��ʵ�֣����ܽ���������������

*/

#include "GL/glew.h"
namespace ErrorNS
{
	/// <summary>
	/// ���
	/// </summary>
	void GLClearError();

	/// <summary>
	/// ��ӡ��־�еĴ�����Ϣ
	/// </summary>
	/// <param name="file">const char* ��C++���ú궨������ͣ������ļ���</param>
	/// <param name="line">�ļ���</param>
	/// <param name="func">�ַ���</param>
	/// <returns></returns>
	bool GLLogError(const char* file, int line, const char* func);
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



