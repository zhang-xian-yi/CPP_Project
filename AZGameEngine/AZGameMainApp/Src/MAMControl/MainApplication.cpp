#include "MainApplication.h"
#include <memory>//�ڴ�
#include "FuncScheduleFactory.h"//ģ����ȹ���
#include "CMNServices/ServiceContainerSingle.h"
#include "CMNMEnum/ModuelType/EModuleType.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"//Ĭ������
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"//Ĭ����Ӧ
#include "CMNMEnum/Command/ECommand.h"//ִ������Ĳ���
namespace AZGameMainApp
{
	MainApplication::MainApplication()
	{
		
	}
	MainApplication::~MainApplication()
	{

	}

	/// <summary>
	/// ��ʼ�����л���
	/// </summary>
	void MainApplication::InitRunEnvirment()
	{
		bool ret = InitAllFunction();
	}
	/// <summary>
	/// �ͷ��������е���Դ
	/// </summary>
	void MainApplication::StopRunEnvirment()
	{
		bool ret = StopAllFunction();

	}
	/// <summary>
	/// ��ʼ�����еĹ���ģ��
	/// </summary>
	bool MainApplication::InitAllFunction()
	{
		auto factory = FuncScheduleNS::FuncScheduleFactory::GetFactory();
		auto pMdlScheduleCtl = factory->CreateModuleInstance();
		//��ʼ�����еĹ���ģ��-Ĭ�ϲ���Ϊ��
		auto mdlInitRep = pMdlScheduleCtl->ConstructModule();
		auto pServiceScheduleCtl = factory->CreateServiceInstance();
		//�������
		std::any cmd = std::make_any<MdlCommonNS::ECommand>(MdlCommonNS::ECommand::E_InitAllFunction);
		auto pRequest = new MdlCommonNS::DefSysRequest(cmd);
		//ִ��E_InitAllFunction ����
		auto cmdReq = std::unique_ptr<MdlCommonNS::ISysRequest>(pRequest);
		auto mdlServiceRep = pServiceScheduleCtl->DoService(cmdReq);
		std::any& repInfo = mdlServiceRep->GetData();
		if (repInfo.has_value())
		{
			//���س�ʼ������Ӧ��ǿ��ת��Ϊbool ���ͣ�ȷ����ʼ������
			bool flag = std::any_cast<bool>(repInfo);
			//����ȷ��flag��ֵ֮����ܷ���
			return flag;
		}

		delete mdlServiceRep;//�ͷ���Ӧ����
		return true;
	}

	bool MainApplication::StopAllFunction()
	{
		auto pServiceOptional = MdlCommonNS::ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_FuncSchedule_Type);
		if (pServiceOptional.has_value())
		{
			//�������		
			std::any cmd = std::make_any<MdlCommonNS::ECommand>(MdlCommonNS::ECommand::E_DestoryAllFunction);
			auto pRequest = new MdlCommonNS::DefSysRequest(cmd);
			//ִ��E_InitAllFunction ����
			auto cmdReq = std::unique_ptr<MdlCommonNS::ISysRequest>(pRequest);
			auto mdlServiceRep = pServiceOptional.value()->DoService(cmdReq);

			delete mdlServiceRep;//�ͷ���Ӧ
		}
		return true;
	}
}