#include "EMdlTypeExtendPrivate.h"

namespace MdlCommonNS
{
	//构造函数
	EMdlTypeExtendPrivate::EMdlTypeExtendPrivate()
		:m_pMdlEnumValueMap(new std::map<EModuleType, std::unique_ptr<EnumValueBean>>())
	{
		initValueMap();
	}

	/// <summary>
	/// 析构函数
	/// </summary>
	EMdlTypeExtendPrivate::~EMdlTypeExtendPrivate()
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
	EnumValueBean* EMdlTypeExtendPrivate::findMdl(EModuleType mdl)const
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
	void EMdlTypeExtendPrivate::initValueMap()
	{


	}

	std::string EMdlTypeExtendPrivate::GetMdlCnDesc(EModuleType mdl)const
	{
		//寻找指定的枚举值所对应的结构
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->CnDesc;
		}
		return std::string("");
	}
	std::string EMdlTypeExtendPrivate::GetMdlEnName(EModuleType mdl)const
	{
		//寻找指定的枚举值所对应的结构
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->EnName;
		}
		return std::string("");
	}
	/// <summary>
	/// 获取模块编码
	/// </summary>
	/// <param name="mdl"></param>
	/// <returns></returns>
	std::string EMdlTypeExtendPrivate::GetMdlCode(EModuleType mdl)const
	{
		//寻找指定的枚举值所对应的结构
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->Code;
		}
		return std::string("");
	}
}