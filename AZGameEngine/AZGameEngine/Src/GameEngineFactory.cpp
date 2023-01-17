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
	/// 创建一个新的业务控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* GameEngineFactory::CreateServiceInstance()
	{
		return new GameEngineServiceControl();
	}

	/// <summary>
	/// 创建一个新的模块控制实例
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* GameEngineFactory::CreateModuleInstance()
	{
		return new GameEngineMdlControl();
	}
}
