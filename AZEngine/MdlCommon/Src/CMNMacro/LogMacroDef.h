#pragma once
#include "CMNExpMarcoDefine.h"
#include <string>

//ǰ������
namespace LoggerNS
{
	enum class ELogLevel :unsigned char;
}

namespace MdlCommonNS
{
	/// <summary>
	/// ����־��׼�������־�ļ���ӡ��Ϣ 
	/// </summary>
	/// <param name="msg"></param>
	/// <returns></returns>
	void MdlCommonDLLAPI LogMsgOSAsync(LoggerNS::ELogLevel logLv, const char* msg);

	template<typename... Args>
	std::string FormatMsg(Args &&... args)
	{
		return (... + args);
	}

	/// <summary>
	/// ��־��ӡ����
	/// </summary>
	/// <typeparam name="...Args"></typeparam>
	/// <param name="loglv"></param>
	/// <param name="...args"></param>
	template<typename... Args>
	void LogMsg(LoggerNS::ELogLevel loglv, Args &&... args)
	{
		auto str = FormatMsg(std::forward<Args>(args)...);
		//��ӡ
		LogMsgOSAsync(loglv, str.c_str());
	}
}

