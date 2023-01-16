#include "EModuleType.h"
#include <map>
#include <memory>
namespace MdlCommonNS
{
	//描述模块枚举所对应的结构信息
	struct SMdlValue
	{
		std::string MdlCode;//模块序列号
		std::string MdlEnName;//模块英文描述
		std::string MdlCnName;//模块中文描述
	};

	//模块枚举值的扩展方法
	class EnumModuleTypeExtendPrivate
	{
	public:
		EnumModuleTypeExtendPrivate();
		~EnumModuleTypeExtendPrivate();
	public:
		//获取模块名字(中文)
		std::string GetMdlCNName(EModuleType mdl)const;
		//获取模块名字(英文)
		std::string GetMdlENName(EModuleType mdl)const;
		//获取模块编码
		std::string GetMdlCode(EModuleType mdl)const;
	private:
		//寻找指定枚举值的定义信息
		SMdlValue* findMdl(EModuleType mdl)const;
		//初始化数据
		void initValueMap();
	private:
		//定义一个此文件内部使用的枚举值列表
	//问题1 在不借助构造函数的情况下如何针对此map进行初始化，原设计为声明全局空类变量
	//利用全局空类的构造函数对本变量进行初始化，这违背命名空间中定义函数的设计
	//那样还不如将这些函数全部封装为类,再将类注册为服务进入系统全局环境中。
		std::map<EModuleType, std::unique_ptr<SMdlValue>>* m_pMdlEnumValueMap;
	};

	//构造函数
	EnumModuleTypeExtendPrivate::EnumModuleTypeExtendPrivate()
		:m_pMdlEnumValueMap(new std::map<EModuleType, std::unique_ptr<SMdlValue>>())
	{
		initValueMap();
	}

	/// <summary>
	/// 析构函数
	/// </summary>
	EnumModuleTypeExtendPrivate::~EnumModuleTypeExtendPrivate()
	{
		if (m_pMdlEnumValueMap != nullptr)
		{
			m_pMdlEnumValueMap->clear();
			delete m_pMdlEnumValueMap;
		}
	}

	/// <summary>
/// 本文件使用的内部函数，搜索本文件全局的静态变量中所存在的模块名称
/// </summary>
/// <param name="mdl"></param>
/// <returns></returns>
	SMdlValue* EnumModuleTypeExtendPrivate::findMdl(EModuleType mdl)const
	{
		//寻找指定的枚举值所对应的结构
		auto findItem = m_pMdlEnumValueMap->find(mdl);
		if (findItem != m_pMdlEnumValueMap->end())
		{
			//找到并返回
			return (*findItem).second.get();
		}
		//没找到
		return nullptr;
	}

	/// <summary>
	/// 初始化数据域
	/// </summary>
	void EnumModuleTypeExtendPrivate::initValueMap()
	{
	}





	std::string EnumModuleTypeExtendPrivate::GetMdlCNName(EModuleType mdl)const
	{
		//寻找指定的枚举值所对应的结构
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->MdlCnName;
		}
		return std::string("");
	}
	std::string EnumModuleTypeExtendPrivate::GetMdlENName(EModuleType mdl)const
	{
		//寻找指定的枚举值所对应的结构
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->MdlEnName;
		}
		return std::string("");
	}
    /// <summary>
    /// 获取模块编码
    /// </summary>
    /// <param name="mdl"></param>
    /// <returns></returns>
    std::string EnumModuleTypeExtendPrivate::GetMdlCode(EModuleType mdl)const
	{
		//寻找指定的枚举值所对应的结构
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->MdlCode;
		}
		return std::string("");
	}


}


