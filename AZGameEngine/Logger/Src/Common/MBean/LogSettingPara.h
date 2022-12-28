#pragma once
namespace Log4CppNS
{
	//设置日志的等级
	enum class ELogLevel :unsigned char
	{
		E_DebugLevel,//调试
		E_InfoLevel,//信息
		E_WarnLevel,//警告
		E_ErrorLevel,//错误
		E_FaultLevel,//崩溃
	};


	//日志设置参数
	struct LogSettingPara
	{

	}; 
}


