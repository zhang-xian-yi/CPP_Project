#include "GameEngineMdlControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

namespace AZGameEngineNS
{
	GameEngineMdlControl::GameEngineMdlControl()
		:m_bIsUse(false)
	{
	}
	GameEngineMdlControl::~GameEngineMdlControl()
	{
	}

	bool GameEngineMdlControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{


		return true;
	}

	bool GameEngineMdlControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{


		return true;
	}



	/// <summary>
	/// ������Ϸ����ģ���״̬
	/// </summary>
	/// <returns></returns>
	bool GameEngineMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}


