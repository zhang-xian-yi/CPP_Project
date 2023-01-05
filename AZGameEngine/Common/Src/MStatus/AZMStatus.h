#pragma once
#include <Common/ExportMarcoDefine.h> //导出宏
#include <string>
namespace CommonNS
{
	//注意 枚举类 允许前置声明
	//描述模块状态和返回信息的数据
	//enum class 枚举类 -> 访问枚举必须加LMStatus的限定符
	//unsigned char 限制枚举类的 数据大小
	enum class CommonDLLAPI AZMStatus :unsigned char;

	CommonDLLAPI std::string GetStatusDesc(AZMStatus status);
	CommonDLLAPI std::string GetStatusHelp(AZMStatus status);
}

