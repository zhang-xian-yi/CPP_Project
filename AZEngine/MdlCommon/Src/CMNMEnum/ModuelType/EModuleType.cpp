#include "EModuleType.h"
#include "EMdlTypeExtendPrivate.h"
#include "CMNMEnum/EnumValueBean.h"
namespace MdlCommonNS
{
	EnumModuleTypeExtend::EnumModuleTypeExtend()
		:m_pService(new EMdlTypeExtendPrivate())
	{
	}

	EnumModuleTypeExtend::~EnumModuleTypeExtend()
	{
		if (m_pService)
		{
			delete m_pService;
			m_pService = nullptr;
		}
	}

	std::string EnumModuleTypeExtend::GetMdlCnDesc(EModuleType mdl) const
	{
		return m_pService->GetMdlCnDesc(mdl);
	}

	std::string EnumModuleTypeExtend::GetMdlEnName(EModuleType mdl) const
	{
		return m_pService->GetMdlEnName(mdl);
	}

	std::string EnumModuleTypeExtend::GetMdlCode(EModuleType mdl) const
	{
		return m_pService->GetMdlCode(mdl);
	}

}


