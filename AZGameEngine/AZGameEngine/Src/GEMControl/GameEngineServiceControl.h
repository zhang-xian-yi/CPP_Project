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
		virtual std::unique_ptr<MdlCommonNS::ISysResponse> DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para = nullptr) override;
	};

}

