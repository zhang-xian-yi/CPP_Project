#include "EMdlTypeExtendPrivate.h"
#include "CMNMEnum/EnumValueBean.h"
namespace MdlCommonNS
{
	//���캯��
	EMdlTypeExtendPrivate::EMdlTypeExtendPrivate()
		:m_pMdlEnumValueMap(new std::map<EModuleType, EnumValueBean*>())
	{
		initValueMap();
	}

	/// <summary>
	/// ��������
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
	/// ���ļ�ʹ�õ��ڲ��������������ļ�ȫ�ֵľ�̬�����������ڵ�ģ������
	/// </summary>
	/// <param name="mdl"></param>
	/// <returns></returns>
	EnumValueBean* EMdlTypeExtendPrivate::findMdl(EModuleType mdl)const
	{
		//Ѱ��ָ����ö��ֵ����Ӧ�Ľṹ
		auto findItem = m_pMdlEnumValueMap->find(mdl);
		if (findItem != m_pMdlEnumValueMap->end())
		{
			//�ҵ�������
			return (*findItem).second;
		}
		//û�ҵ�
		return nullptr;
	}

	std::string EMdlTypeExtendPrivate::GetMdlCnDesc(EModuleType mdl)const
	{
		//Ѱ��ָ����ö��ֵ����Ӧ�Ľṹ
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->CnDesc;
		}
		return std::string("");
	}
	std::string EMdlTypeExtendPrivate::GetMdlEnName(EModuleType mdl)const
	{
		//Ѱ��ָ����ö��ֵ����Ӧ�Ľṹ
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->EnName;
		}
		return std::string("");
	}
	/// <summary>
	/// ��ȡģ�����
	/// </summary>
	/// <param name="mdl"></param>
	/// <returns></returns>
	std::string EMdlTypeExtendPrivate::GetMdlCode(EModuleType mdl)const
	{
		//Ѱ��ָ����ö��ֵ����Ӧ�Ľṹ
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->Code;
		}
		return std::string("");
	}

	/// <summary>
	/// ��ʼ��������
	/// </summary>
	void EMdlTypeExtendPrivate::initValueMap()
	{
		//		m_pMdlEnumValueMap->insert(std::make_pair(EModuleType::E_Logger_Type, new EnumValueBean("", "", "")));

		m_pMdlEnumValueMap->insert(std::make_pair(EModuleType::E_FuncSchedule_Type, new EnumValueBean("FS001", "FSMdl", "���ܵ���ģ��")));
		m_pMdlEnumValueMap->insert(std::make_pair(EModuleType::E_GameEngine_Type, new EnumValueBean("GE002", "GEMdl", "��Ϸ����ģ��")));
		m_pMdlEnumValueMap->insert(std::make_pair(EModuleType::E_Logger_Type, new EnumValueBean("L003", "LMdl", "��־ģ��")));
		m_pMdlEnumValueMap->insert(std::make_pair(EModuleType::E_OpengGLUI_Type, new EnumValueBean("OG004", "OGMdl", "Opengl����ģ��")));
	}
}