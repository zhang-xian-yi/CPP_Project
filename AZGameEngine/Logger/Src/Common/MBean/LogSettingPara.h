#pragma once
namespace Log4CppNS
{
	//日志的等级
	enum class ELogLevel :unsigned char
	{
		E_DebugLevel,//调试
		E_InfoLevel,//信息
		E_WarnLevel,//警告
		E_ErrorLevel,//错误
		E_FaultLevel,//崩溃
	};

	//日志的等级
	enum class ELogTarget :unsigned char
	{
		E_Console,//控制台
		E_LogFile,//日志文件
	};


	//日志设置参数
	struct LogSettingPara
	{
		ELogLevel logLevel;//日志等级
		ELogTarget logTarget;//日志目标
	}; 
}


