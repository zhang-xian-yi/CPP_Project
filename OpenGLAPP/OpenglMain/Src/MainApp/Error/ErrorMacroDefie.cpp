#include "ErrorMacroDefie.h"

#include <iostream>
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
}
