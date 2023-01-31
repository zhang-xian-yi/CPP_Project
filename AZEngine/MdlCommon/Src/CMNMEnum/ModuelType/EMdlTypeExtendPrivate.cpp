#include "EMdlTypeExtendPrivate.h"
#include "CMNMEnum/EnumValueBean.h"
namespace MdlCommonNS
{
	//构造函数
	EMdlTypeExtendPrivate::EMdlTypeExtendPrivate()
		:m_pMdlEnumValueMap(new std::map<EModuleType, EnumValueBean*>())
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
			for (auto&[key1,val2]:*m_pMdlEnumValueMap)
			{
				delete val2;
			}
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
			return (*findItem).second;
		}
		//没找到
		return nullptr;
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

	/// <summary>
	/// 初始化数据域
	/// </summary>
	void EMdlTypeExtendPrivate::initValueMap()
	{
		//		m_pMdlEnumValueMap->insert(std::make_pair(EModuleType::E_Logger_Type, new EnumValueBean("", "", "")));

		m_pMdlEnumValueMap->insert(std::make_pair(EModuleType::E_FuncSchedule_Type, new EnumValueBean("FS001", "FSMdl", "功能调度模块")));
		m_pMdlEnumValueMap->insert(std::make_pair(EModuleType::E_GameEngine_Type, new EnumValueBean("GE002", "GEMdl", "游戏引擎模块")));
		m_pMdlEnumValueMap->insert(std::make_pair(EModuleType::E_Logger_Type, new EnumValueBean("L003", "LMdl", "日志模块")));
		m_pMdlEnumValueMap->insert(std::make_pair(EModuleType::E_OpengGLUI_Type, new EnumValueBean("OG004", "OGMdl", "Opengl窗口模块")));
	}
}