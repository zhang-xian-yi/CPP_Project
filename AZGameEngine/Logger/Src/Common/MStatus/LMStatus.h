#pragma once

namespace Log4CppNS
{
	//注意 枚举类 允许前置声明
	//描述模块状态和返回信息的数据
	//enum class 枚举类 -> 访问枚举必须加LMStatus的限定符
	//unsigned char 限制枚举类的 数据大小
	enum class LMStatus:unsigned char
	{
		E_ModuleInit_Succ,//模块初始化成功
		E_ModuleInit_Failed,//模块初始化失败
		E_ModuleRunning,//模块正在运行
		E_ModuleNotInit,//模块没有初始化
		E_ModuleNotUse,//模块不可用
	};
}

