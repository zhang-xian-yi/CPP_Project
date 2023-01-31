#pragma once
#include <map>
#include <memory>
#include "EModuleType.h"
namespace MdlCommonNS
{
	//前置声明
	class EnumValueBean;

	//模块枚举值的扩展方法
	class EMdlTypeExtendPrivate
	{
	public:
		EMdlTypeExtendPrivate();
		~EMdlTypeExtendPrivate();
	public:
		//获取模块名字(中文)
		std::string GetMdlCnDesc(EModuleType mdl)const;
		//获取模块名字(英文)
		std::string GetMdlEnName(EModuleType mdl)const;
		//获取模块编码
		std::string GetMdlCode(EModuleType mdl)const;
	private:
		//寻找指定枚举值的定义信息
		EnumValueBean* findMdl(EModuleType mdl)const;
		//初始化数据
		void initValueMap();
	private:
		//定义一个此文件内部使用的枚举值列表
		//问题1 在不借助构造函数的情况下如何针对此map进行初始化，原设计为声明全局空类变量
		//利用全局空类的构造函数对本变量进行初始化，这违背命名空间中定义函数的设计
		//那样还不如将这些函数全部封装为类,再将类注册为服务进入系统全局环境中。
		std::map<EModuleType, EnumValueBean*>* m_pMdlEnumValueMap;
	};
}