#pragma once
#include <string>
namespace MdlCommonNS
{
	//描述模块枚举所对应的结构信息
	struct EnumValueBean
	{
		std::string Code;//模块序列号
		std::string EnName;//模块英文名字
		std::string CnDesc;//模块中文描述
	};
}