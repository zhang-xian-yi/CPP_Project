#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //������

namespace CommonNS
{
	//ö��ģ������
	enum class EModuleType :unsigned char
	{
	};

	//ģ��ö��ֵ����չ����
	class CommonDLLAPI EnumModuleTypeExtend
	{
	public:
		//��ȡģ������(����)
		std::string GetMdlCNName(EModuleType mdl)const;
		//��ȡģ������(Ӣ��)
		std::string GetMdlENName(EModuleType mdl)const;
		//��ȡģ�����
		std::string GetMdlCode(EModuleType mdl)const;
	};
}

