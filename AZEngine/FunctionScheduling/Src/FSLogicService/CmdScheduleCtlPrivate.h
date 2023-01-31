#pragma once
#include <map>
#include <unordered_map>
#include <memory>
#include "IService.h"//ICmdService,IFuncService 引入
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
/*
注意 功能模块的调度通过全局容器存储的模式处理
     系统命令通过集中-分散的模式进行处理
*/

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
	class CmdScheduleCtlPrivate
	{
	public:
		CmdScheduleCtlPrivate();
		~CmdScheduleCtlPrivate();
		//选择业务的分支
		MdlCommonNS::ISysResponse* SwitchCmdService(MdlCommonNS::ECommand cmd);
		//选择业务的分支
		MdlCommonNS::ISysResponse* SwitchFuncService(MdlCommonNS::EModuleType mdlTpye,const std::unique_ptr<MdlCommonNS::ISysRequest>& para);
	private:
		void InitData();
	private:
		//保存系统命令和实现业务逻辑的映射表
		std::unordered_map<MdlCommonNS::ECommand, ICmdService*>* m_pCmdServiceMap;
	};
}


