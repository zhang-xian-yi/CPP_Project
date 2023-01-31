#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏

namespace MdlCommonNS
{
	//枚举模块类型
	enum class EModuleType :unsigned char
	{
		E_Logger_Type,
		E_FuncSchedule_Type,
		E_GameEngine_Type,
		E_OpengGLUI_Type
	};

	//前置声明
	class EMdlTypeExtendPrivate;

	//模块枚举值的扩展方法
	class MdlCommonDLLAPI EnumModuleTypeExtend
	{
	public:
		static EnumModuleTypeExtend* GetInstance()
		{
			static EnumModuleTypeExtend instance;
			return &instance;
		}
	private:
		//禁止反复定义工厂，禁止delelte 工厂对象
		EnumModuleTypeExtend();
		~EnumModuleTypeExtend();
		EnumModuleTypeExtend(EnumModuleTypeExtend& instance) = delete;
		EnumModuleTypeExtend& operator=(const EnumModuleTypeExtend& instance) = delete;
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

