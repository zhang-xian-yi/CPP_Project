#include "FuncScheduleControl.h"
#include <typeinfo>
#include "FSLogicService/CmdScheduleCtlPrivate.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"
#include "CMNMEnum/Command/ECommand.h"
#include "CMNMEnum/ModuelType/EModuleType.h"
namespace FuncScheduleNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	FuncScheduleControl::FuncScheduleControl()
		:m_pCmdCtl(new CmdScheduleCtlPrivate())
	{
	}
	/// <summary>
	/// 析构函数
	/// </summary>
	FuncScheduleControl::~FuncScheduleControl()
	{
		if (m_pCmdCtl != nullptr)
		{
			delete m_pCmdCtl;
			m_pCmdCtl = nullptr;
		}
	}
	/// <summary>
	/// 执行调度逻辑
	/// </summary>
	/// <param name="para"></param>
	/// <returns></returns>
	MdlCommonNS::ISysResponse* FuncScheduleControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para)
	{
		//获取请求数据
		std::any& requestData = para->GetData();
		//执行业务逻辑
		if (requestData.type() == typeid(MdlCommonNS::ECommand))
		{
			//命令调度--转换命令
			MdlCommonNS::ECommand& cmd = std::any_cast<MdlCommonNS::ECommand&>(requestData);
			//执行调度
			return m_pCmdCtl->SwitchCmdService(cmd);
		}
		else
		{
			//功能调度
			return m_pCmdCtl->SwitchFuncService(MdlCommonNS::EModuleType::E_Logger_Type,para);
		}
	}
}