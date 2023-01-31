#include "FuncScheduleControl.h"
#include <typeinfo>
#include "FSLogicService/CmdScheduleCtlPrivate.h"

#include "CMNMEnum/ModuelType/EModuleType.h"
namespace FuncScheduleNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	FuncScheduleControl::FuncScheduleControl()
		:m_pCmdCtl(new CmdScheduleCtlPrivate())
	{
	}
	/// <summary>
	/// ��������
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
	/// ִ�е����߼�
	/// </summary>
	/// <param name="para"></param>
	/// <returns></returns>
	std::any FuncScheduleControl::ExecuteCmd(MdlCommonNS::ECommand cmd)
	{
		//ִ�е���
		return m_pCmdCtl->SwitchCmdService(cmd);
	}
}