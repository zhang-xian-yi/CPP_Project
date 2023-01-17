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

	//ǰ������
	class EMdlTypeExtendPrivate;

	//ģ��ö��ֵ����չ����
	class MdlCommonDLLAPI EnumModuleTypeExtend
	{
	public:
		EnumModuleTypeExtend();
		~EnumModuleTypeExtend();
	public:
		//��ȡģ������(����)
		std::string GetMdlCnDesc(EModuleType mdl)const;
		//��ȡģ������(Ӣ��)
		std::string GetMdlEnName(EModuleType mdl)const;
		//��ȡģ�����
		std::string GetMdlCode(EModuleType mdl)const;
	private:
		EMdlTypeExtendPrivate* m_pService;
	};
}

