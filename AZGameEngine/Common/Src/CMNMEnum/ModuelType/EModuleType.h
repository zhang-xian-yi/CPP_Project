#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏

namespace CommonNS
{
	//枚举模块类型
	enum class EModuleType :unsigned char
	{
	};

	//模块枚举值的扩展方法
	class CommonDLLAPI EnumModuleTypeExtend
	{
	public:
		//获取模块名字(中文)
		std::string GetMdlCNName(EModuleType mdl)const;
		//获取模块名字(英文)
		std::string GetMdlENName(EModuleType mdl)const;
		//获取模块编码
		std::string GetMdlCode(EModuleType mdl)const;
	};
}

