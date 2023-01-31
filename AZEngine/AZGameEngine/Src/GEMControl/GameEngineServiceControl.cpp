#include "GameEngineServiceControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

namespace AZGameEngineNS
{
	GameEngineServiceControl::GameEngineServiceControl()
	{
	}

	GameEngineServiceControl::~GameEngineServiceControl()
	{
	}

	MdlCommonNS::ISysResponse* GameEngineServiceControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return pResult;
	}

}

