#pragma once
#include <string>
#include "Common/MarcoDefine.h"
namespace Log4CppNS
{
	enum class ELogLevel :unsigned char;

	//日志的等级
	enum class ELogTarget :unsigned char;

	//日志设置参数
	struct LogerAPI LogSettingPara
	{
		ELogLevel logLevel;//日志等级
		ELogTarget logTarget;//日志目标
	};

	//日志信息的参数
	struct LogerAPI LogMsgPara
	{
		std::string message;
	};
}

