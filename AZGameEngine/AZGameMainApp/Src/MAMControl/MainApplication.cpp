#include "MainApplication.h"
#include <memory>//�ڴ�
#include "FuncScheduleFactory.h"//ģ����ȹ���

#include "CMNEntity/DefaultReqRep/DefSysRequest.h"//Ĭ������
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"//Ĭ����Ӧ
#include "CMNEntity/Any.h"//�������͵�������
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
	/// ��ʼ�����еĹ���ģ��
	/// </summary>
	bool& MainApplication::InitAllFunction()
	{
		auto factory = FuncScheduleNS::FuncScheduleFactory::GetFactory();
		auto pMdlScheduleCtl = factory->CreateModuleInstance();
		//��ʼ�����еĹ���ģ��-Ĭ�ϲ���Ϊ��
		auto mdlInitRep = pMdlScheduleCtl->ConstructModule();
		auto pServiceScheduleCtl = factory->CreateServiceInstance();
		//�������
		auto pRequest = new MdlCommonNS::DefSysRequest();
		MdlCommonNS::Any cmd = MdlCommonNS::ECommand::E_InitAllFunction;
		pRequest->SetData(cmd);
		//ִ��E_InitAllFunction ����
		auto mdlServiceRep = pServiceScheduleCtl->DoService(std::unique_ptr<MdlCommonNS::ISysRequest>(pRequest));
		MdlCommonNS::Any& repInfo = mdlServiceRep->GetData();
		//���س�ʼ������Ӧ��ǿ��ת��Ϊbool ���ͣ�ȷ����ʼ������
		return repInfo.AnyRefCast<bool>();
		//return true;
	}
}