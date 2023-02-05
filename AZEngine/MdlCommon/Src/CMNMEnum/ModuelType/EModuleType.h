#pragma once
#include <string>
#include "MdlCommon/Src/CMNMacro/CMNExpMarcoDefine.h" //导出宏
#include "MdlCommon/Src/CMNMacro/TypeMacroDef.h"
#include "MdlCommon/Src/CMNMacro/CoreMacroDef.h"
namespace MdlCommonNS
{
	//枚举模块类型
	enum class EModuleType :unsigned char
	{
		E_Logger_Type,
		E_FuncSchedule_Type,
		E_DataCompute_Type,
		E_AZWindows_Type,
		E_SysEventDriven_Type,
		E_OpenGLWindow_Type,
	};

	//前置声明
	class EMdlTypeExtendPrivate;

	//模块枚举值的扩展方法
	class MdlCommonDLLAPI EnumModuleTypeExtend
	{
		SingletonSelfConstruct(EnumModuleTypeExtend)
	public:
		//获取模块描述(中文)
		std::string GetMdlCnDesc(EModuleType mdl)const;
		//获取模块名字(英文)
		std::string GetMdlEnName(EModuleType mdl)const;
		//获取模块编码
		std::string GetMdlCode(EModuleType mdl)const;
	private:
		EMdlTypeExtendPrivate* m_pService;
	};
}

