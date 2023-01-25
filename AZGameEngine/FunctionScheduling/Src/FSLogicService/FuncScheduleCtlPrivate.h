#pragma once
#include <map>
#include <memory>
#include "IService.h"//ICmdService,IFuncService 引入
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace MdlCommonNS
{
	//前置声明
	enum class ECommand :unsigned char;
	enum class EModuleType :unsigned char;
}
namespace FuncScheduleNS
{
	/// <summary>
	/// 模块调度的控制器实现私有逻辑
	/// </summary>
	class FuncScheduleCtlPrivate
	{
	public:
		FuncScheduleCtlPrivate();
		~FuncScheduleCtlPrivate();
		//选择业务的分支
		std::unique_ptr<MdlCommonNS::ISysResponse> SwitchCmdService(MdlCommonNS::ECommand cmd);
		//选择业务的分支
		std::unique_ptr<MdlCommonNS::ISysResponse> SwitchFuncService(MdlCommonNS::EModuleType mdlTpye,const std::unique_ptr<MdlCommonNS::ISysRequest>& para);
	private:
		//保存系统命令和实现业务逻辑的映射表
		std::map<MdlCommonNS::ECommand, std::unique_ptr<ICmdService>>* m_pCmdServiceMap;
		//保存用户命令和实现业务逻辑的映射表
		std::map<MdlCommonNS::EModuleType, std::unique_ptr<IFuncService>>* m_pFuncServiceMap;
	};
}


