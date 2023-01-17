#pragma once
#include <map>
#include <memory>
#include "CMNMEnum/EnumValueBean.h"
#include "EModuleType.h"
namespace MdlCommonNS
{

	//ģ��ö��ֵ����չ����
	class EMdlTypeExtendPrivate
	{
	public:
		EMdlTypeExtendPrivate();
		~EMdlTypeExtendPrivate();
	public:
		//��ȡģ������(����)
		std::string GetMdlCnDesc(EModuleType mdl)const;
		//��ȡģ������(Ӣ��)
		std::string GetMdlEnName(EModuleType mdl)const;
		//��ȡģ�����
		std::string GetMdlCode(EModuleType mdl)const;
	private:
		//Ѱ��ָ��ö��ֵ�Ķ�����Ϣ
		EnumValueBean* findMdl(EModuleType mdl)const;
		//��ʼ������
		void initValueMap();
	private:
		//����һ�����ļ��ڲ�ʹ�õ�ö��ֵ�б�
		//����1 �ڲ��������캯��������������Դ�map���г�ʼ����ԭ���Ϊ����ȫ�ֿ������
		//����ȫ�ֿ���Ĺ��캯���Ա��������г�ʼ������Υ�������ռ��ж��庯�������
		//���������罫��Щ����ȫ����װΪ��,�ٽ���ע��Ϊ�������ϵͳȫ�ֻ����С�
		std::map<EModuleType, std::unique_ptr<EnumValueBean>>* m_pMdlEnumValueMap;
	};
}