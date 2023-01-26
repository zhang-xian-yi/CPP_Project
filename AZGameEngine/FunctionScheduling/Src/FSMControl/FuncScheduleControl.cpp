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
	MdlCommonNS::ISysResponse* FuncScheduleControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para)
	{
		//��ȡ��������
		std::any& requestData = para->GetData();
		//ִ��ҵ���߼�
		if (requestData.type() == typeid(MdlCommonNS::ECommand))
		{
			//�������--ת������
			MdlCommonNS::ECommand& cmd = std::any_cast<MdlCommonNS::ECommand&>(requestData);
			//ִ�е���
			return m_pCmdCtl->SwitchCmdService(cmd);
		}
		else
		{
			//���ܵ���
			return m_pCmdCtl->SwitchFuncService(MdlCommonNS::EModuleType::E_Logger_Type,para);
		}
	}
}