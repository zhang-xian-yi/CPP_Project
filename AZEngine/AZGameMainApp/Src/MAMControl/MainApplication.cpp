#include "MainApplication.h"
#include <memory>//�ڴ�
#include "FunctionScheduling/Src/FuncScheduleFactory.h"//ģ����ȹ���
#include "FunctionScheduling/Src/IFuncSchedule.h"
#include "Logger/Src/ILogger.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNMEnum/Command/ECommand.h"//ִ������Ĳ���
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
	/// �ͷ����������е���Դ
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
		bool mdlInitRep = pMdlScheduleCtl->ConstructModule();
		auto pServiceScheduleCtl = factory->CreateServiceInstance();
		//ע��ģ��
		MdlCommonNS::ServiceContainerSingle::GetContainer().RegisterModuleInterface(MdlCommonNS::EModuleType::E_FuncSchedule_Type, pMdlScheduleCtl, pServiceScheduleCtl);

		auto pService = pServiceScheduleCtl->ConvertType<FuncScheduleNS::IFuncSchedule*>();
		std::any mdlServiceRep = pService->ExecuteCmd(MdlCommonNS::ECommand::E_InitAllFunction);
		if (mdlServiceRep.has_value())
		{
			//���س�ʼ������Ӧ��ǿ��ת��Ϊbool ���ͣ�ȷ����ʼ������
			//��Ӧ���ʼ���������
			std::tuple<bool, std::string> flag = std::any_cast<std::tuple<bool, std::string>>(mdlServiceRep);
			//����ȷ��flag��ֵ֮����ܷ���
			return std::get<0>(flag);
		}
		return false;
	}

	bool MainApplication::StopAllFunction()
	{
		auto pServiceOptional = MdlCommonNS::ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_FuncSchedule_Type);
		if (pServiceOptional.has_value())
		{
			auto pService = pServiceOptional.value()->ConvertType<FuncScheduleNS::IFuncSchedule*>();
			//�������		
			std::any stopRep = pService->ExecuteCmd(MdlCommonNS::ECommand::E_DestoryAllFunction);
			//���س�ʼ������Ӧ��ǿ��ת��Ϊbool ���ͣ�ȷ����ʼ������
			std::tuple<bool, std::string> flag = std::any_cast<std::tuple<bool, std::string>>(stopRep);
			//����ȷ��flag��ֵ֮����ܷ���
			return std::get<0>(flag);
		}
		return false;
	}
}