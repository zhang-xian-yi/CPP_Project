#include "FuncScheduleControl.h"
#include <typeinfo>
#include "FSLogicService/FuncScheduleCtlPrivate.h"
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
		:m_pService(new FuncScheduleCtlPrivate())
	{
	}
	/// <summary>
	/// ��������
	/// </summary>
	FuncScheduleControl::~FuncScheduleControl()
	{
		if (m_pService != nullptr)
		{
			delete m_pService;
			m_pService = nullptr;
		}
	}
	/// <summary>
	/// ִ�е����߼�
	/// </summary>
	/// <param name="para"></param>
	/// <returns></returns>
	std::unique_ptr<MdlCommonNS::ISysResponse> FuncScheduleControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para)
	{
		//��ȡ��������
		std::any& requestData = para->GetData();
		//ִ��ҵ���߼�
		if (requestData.type() == typeid(MdlCommonNS::ECommand))
		{
			//�������--ת������
			MdlCommonNS::ECommand& cmd = std::any_cast<MdlCommonNS::ECommand&>(requestData);
			//ִ�е���
			m_pService->SwitchCmdService(cmd);
			//���췵�ز���
			std::any data = std::make_any<bool>(true);
			auto pResult = new MdlCommonNS::DefSysResponse(data);
			return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
		}
		else
		{
			//���ܵ���
			return m_pService->SwitchFuncService(MdlCommonNS::EModuleType::E_Logger_Type,para);
		}
	}
}