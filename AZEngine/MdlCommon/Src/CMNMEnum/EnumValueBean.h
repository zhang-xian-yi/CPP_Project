#pragma once
#include <string>
namespace MdlCommonNS
{
	//����ģ��ö������Ӧ�Ľṹ��Ϣ
	class EnumValueBean
	{
	public:
		std::string Code;//ģ�����к�
		std::string EnName;//ģ��Ӣ������
		std::string CnDesc;//ģ����������
	public:
		EnumValueBean(const std::string&& icode, const std::string&& ienName, const std::string&& icnDesc)
		{
			Code = icode;
			EnName = ienName;
			CnDesc = icnDesc;
		}
	};
}