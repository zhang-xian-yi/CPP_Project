#pragma once
#include <string>
#include "MdlCommon/Src/CMNMacro/CMNExpMarcoDefine.h" //������
#include "MdlCommon/Src/CMNMacro/TypeMacroDef.h"
#include "MdlCommon/Src/CMNMacro/CoreMacroDef.h"
namespace MdlCommonNS
{
	//ö��ģ������
	enum class EModuleType :unsigned char
	{
		E_Logger_Type,
		E_FuncSchedule_Type,
		E_DataCompute_Type,
		E_AZWindows_Type,
		E_SysEventDriven_Type,
		E_OpenGLWindow_Type,
	};

	//ǰ������
	class EMdlTypeExtendPrivate;

	//ģ��ö��ֵ����չ����
	class MdlCommonDLLAPI EnumModuleTypeExtend
	{
		SingletonSelfConstruct(EnumModuleTypeExtend)
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

