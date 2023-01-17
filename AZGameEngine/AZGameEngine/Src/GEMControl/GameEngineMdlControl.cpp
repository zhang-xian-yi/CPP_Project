#include "GameEngineMdlControl.h"

namespace AZGameEngineNS
{
	GameEngineMdlControl::GameEngineMdlControl()
		:m_bIsUse(false)
	{
	}
	GameEngineMdlControl::~GameEngineMdlControl()
	{
	}

	MdlCommonNS::ISysResponse* GameEngineMdlControl::ConstructModule(const MdlCommonNS::ISysRequest* para)
	{
		return nullptr;
	}
	MdlCommonNS::ISysResponse* GameEngineMdlControl::DestoryModule(const MdlCommonNS::ISysRequest* para)
	{
		return nullptr;
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


