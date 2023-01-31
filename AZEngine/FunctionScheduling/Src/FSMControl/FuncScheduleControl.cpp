#include "FuncScheduleControl.h"
#include <typeinfo>
#include "FSLogicService/CmdScheduleCtlPrivate.h"

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
	std::any FuncScheduleControl::ExecuteCmd(MdlCommonNS::ECommand cmd)
	{
		//执行调度
		return m_pCmdCtl->SwitchCmdService(cmd);
	}
}