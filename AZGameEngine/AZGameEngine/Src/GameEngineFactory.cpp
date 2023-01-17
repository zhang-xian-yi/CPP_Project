#include "GameEngineFactory.h"
#include <GEMControl/GameEngineMdlControl.h>
#include <GEMControl/GameEngineServiceControl.h>
namespace AZGameEngineNS
{
	GameEngineFactory::GameEngineFactory()
	{
	}
	GameEngineFactory::~GameEngineFactory()
	{
	}

	/// <summary>
	/// ����һ���µ�ҵ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* GameEngineFactory::CreateServiceInstance()
	{
		return new GameEngineServiceControl();
	}

	/// <summary>
	/// ����һ���µ�ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* GameEngineFactory::CreateModuleInstance()
	{
		return new GameEngineMdlControl();
	}
}
