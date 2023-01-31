#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
namespace MdlCommonNS
{
	//枚举模块类型
	enum class ECommand :unsigned char
	{
		E_InitAllFunction,//初始化所有的功能模块
		E_DestoryAllFunction,//销毁所有的功能模块
	};

	//模块枚举值的扩展方法
	class MdlCommonDLLAPI EnumCommandExtend
	{
	public:
		//获取命令描述(中文)
		std::string GetCmdCnDesc(ECommand mdl)const;
		//获取命令编码
		std::string GetMdlCode(ECommand mdl)const;
	};
}