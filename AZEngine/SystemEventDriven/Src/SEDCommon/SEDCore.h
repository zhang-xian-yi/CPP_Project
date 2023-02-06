#pragma once
namespace LoggerNS
{
	enum class ELogLevel :unsigned char;
}

#include <string>
namespace SysEventDNS
{
//����
#define LBit1(x) (1 << x)

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
	void LogMsg(LoggerNS::ELogLevel loglv, Args &&... args)
	{
		auto str = FormatMsg(std::forward<Args>(args)...);
		//��ӡ
		LogMsgOSAsync(loglv, str.c_str());
	}
}