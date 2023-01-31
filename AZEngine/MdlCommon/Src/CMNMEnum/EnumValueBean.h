#pragma once
#include <string>
namespace MdlCommonNS
{
	//描述模块枚举所对应的结构信息
	class EnumValueBean
	{
	public:
		std::string Code;//模块序列号
		std::string EnName;//模块英文名字
		std::string CnDesc;//模块中文描述
	public:
		EnumValueBean(const std::string&& icode, const std::string&& ienName, const std::string&& icnDesc)
		{
			Code = icode;
			EnName = ienName;
			CnDesc = icnDesc;
		}
	};
}