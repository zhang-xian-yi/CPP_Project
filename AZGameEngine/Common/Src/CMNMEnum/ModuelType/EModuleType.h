#pragma once
#include <string>
#include <CMNCommon/CMNExpMarcoDefine.h> //导出宏

namespace CommonNS
{
	enum class EModuleType:unsigned char
	{
	};

	//获取模块名字
	CommonDLLAPI std::string GetModuleName(EModuleType mdl);
}

