#include "EModuleType.h"
#include <map>
#include <memory>
namespace MdlCommonNS
{
	//����ģ��ö������Ӧ�Ľṹ��Ϣ
	struct SMdlValue
	{
		std::string MdlCode;//ģ�����к�
		std::string MdlEnName;//ģ��Ӣ������
		std::string MdlCnName;//ģ����������
	};

	//ģ��ö��ֵ����չ����
	class EnumModuleTypeExtendPrivate
	{
	public:
		EnumModuleTypeExtendPrivate();
		~EnumModuleTypeExtendPrivate();
	public:
		//��ȡģ������(����)
		std::string GetMdlCNName(EModuleType mdl)const;
		//��ȡģ������(Ӣ��)
		std::string GetMdlENName(EModuleType mdl)const;
		//��ȡģ�����
		std::string GetMdlCode(EModuleType mdl)const;
	private:
		//Ѱ��ָ��ö��ֵ�Ķ�����Ϣ
		SMdlValue* findMdl(EModuleType mdl)const;
		//��ʼ������
		void initValueMap();
	private:
		//����һ�����ļ��ڲ�ʹ�õ�ö��ֵ�б�
	//����1 �ڲ��������캯��������������Դ�map���г�ʼ����ԭ���Ϊ����ȫ�ֿ������
	//����ȫ�ֿ���Ĺ��캯���Ա��������г�ʼ������Υ�������ռ��ж��庯�������
	//���������罫��Щ����ȫ����װΪ��,�ٽ���ע��Ϊ�������ϵͳȫ�ֻ����С�
		std::map<EModuleType, std::unique_ptr<SMdlValue>>* m_pMdlEnumValueMap;
	};

	//���캯��
	EnumModuleTypeExtendPrivate::EnumModuleTypeExtendPrivate()
		:m_pMdlEnumValueMap(new std::map<EModuleType, std::unique_ptr<SMdlValue>>())
	{
		initValueMap();
	}

	/// <summary>
	/// ��������
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
/// ���ļ�ʹ�õ��ڲ��������������ļ�ȫ�ֵľ�̬�����������ڵ�ģ������
/// </summary>
/// <param name="mdl"></param>
/// <returns></returns>
	SMdlValue* EnumModuleTypeExtendPrivate::findMdl(EModuleType mdl)const
	{
		//Ѱ��ָ����ö��ֵ����Ӧ�Ľṹ
		auto findItem = m_pMdlEnumValueMap->find(mdl);
		if (findItem != m_pMdlEnumValueMap->end())
		{
			//�ҵ�������
			return (*findItem).second.get();
		}
		//û�ҵ�
		return nullptr;
	}

	/// <summary>
	/// ��ʼ��������
	/// </summary>
	void EnumModuleTypeExtendPrivate::initValueMap()
	{
	}





	std::string EnumModuleTypeExtendPrivate::GetMdlCNName(EModuleType mdl)const
	{
		//Ѱ��ָ����ö��ֵ����Ӧ�Ľṹ
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->MdlCnName;
		}
		return std::string("");
	}
	std::string EnumModuleTypeExtendPrivate::GetMdlENName(EModuleType mdl)const
	{
		//Ѱ��ָ����ö��ֵ����Ӧ�Ľṹ
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->MdlEnName;
		}
		return std::string("");
	}
    /// <summary>
    /// ��ȡģ�����
    /// </summary>
    /// <param name="mdl"></param>
    /// <returns></returns>
    std::string EnumModuleTypeExtendPrivate::GetMdlCode(EModuleType mdl)const
	{
		//Ѱ��ָ����ö��ֵ����Ӧ�Ľṹ
		auto pointer = findMdl(mdl);
		if (nullptr != pointer)
		{
			return pointer->MdlCode;
		}
		return std::string("");
	}


}


