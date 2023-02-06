#pragma once
/*
ע�� �����CPP�ļ�Ϊ�˽����ζ������������⣬
�����ȫ�ֺ����������������������һ��ʵ�֣����ܽ���������������

*/
//ǰ������
namespace LoggerNS
{
	enum class ELogLevel :unsigned char;
}

#include <string>
namespace WindowsNS
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

	/// <summary>
	/// ����־��׼�������־�ļ���ӡ��Ϣ 
	/// </summary>
	/// <param name="msg"></param>
	/// <returns></returns>
	void LogMsgOSAsync(LoggerNS::ELogLevel logLv,const char* msg);

	template<typename... Args>
	std::string FormatMsg(Args &&... args)
	{
		return (... + args);
	}

	template<typename... Args>
	void LogMsg(LoggerNS::ELogLevel loglv,Args &&... args)
	{
		auto str = FormatMsg(std::forward<Args>(args)...);
		//��ӡ
		LogMsgOSAsync(loglv,str.c_str());
	}
}




//ע��debugbreak() ��һ�������жϵĺ���
//�ú궨����ζ��һ������xΪfalse �����������ж�
//ֻ��MSVC�д��ڣ� ��������CLang����GCC��
#define MacroDefAssert(x) if(!(x)) __debugbreak();

//ͨ�����滻�ķ�ʽ��X����ִ�й����滻Ϊ���κ���ִ�еĹ���
//���������⣬������־��Ϣ��ӡ�ȡ������ж�
//ע��#x ���Խ�X����ת��Ϊ�ַ���
#define GLCallWarn(x) WindowsNS::GLClearError();\
					  x;\
					  MacroDefAssert(WindowsNS::GLLogError(__FILE__,__LINE__,#x))


