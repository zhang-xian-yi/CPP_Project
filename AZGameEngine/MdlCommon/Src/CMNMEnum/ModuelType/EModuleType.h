#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //������

namespace MdlCommonNS
{
	//ö��ģ������
	enum class EModuleType :unsigned char
	{
		E_Logger_Type,
		E_FuncSchedule_Type,
		E_GameEngine_Type,
		E_OpengGLUI_Type
	};

	//ģ��ö��ֵ����չ����
	class MdlCommonDLLAPI EnumModuleTypeExtend
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

