#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"

namespace AZGameEngineNS
{
	/// <summary>
	/// ��Ϸ�����ҵ���߼�������
	/// </summary>
	class GameEngineServiceControl :public MdlCommonNS::IMdlService
	{
	public:
		GameEngineServiceControl();
		~GameEngineServiceControl();
	public:
		virtual MdlCommonNS::ISysResponse* DoService(const MdlCommonNS::ISysRequest* para) override;
	};

}

