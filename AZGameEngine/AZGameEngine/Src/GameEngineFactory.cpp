#include "GameEngineFactory.h"
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/IMdlService.h"

namespace AZGameEngineNS
{
	GameEngineFactory::GameEngineFactory()
	{
	}
	GameEngineFactory::~GameEngineFactory()
	{
	}
	MdlCommonNS::IMdlService* GameEngineFactory::GetServiceInstance()
	{
		return nullptr;
	}
	MdlCommonNS::IMdlOperat* GameEngineFactory::GetModuleInstance()
	{
		return nullptr;
	}
}
