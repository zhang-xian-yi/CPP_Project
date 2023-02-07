#include "MainApplication.h"
#include <memory>//�ڴ�
#include "FunctionScheduling/Src/FuncScheduleFactory.h"//ģ����ȹ���
#include "FunctionScheduling/Src/IFuncSchedule.h"
#include "Logger/Src/ILogger.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNMEnum/Command/ECommand.h"//ִ������Ĳ���
#include "EventDrivenSystem/Src/ISystemEvent.h"
#include "OpenGLWindowUI/Src/IWindow.h"
namespace AZGameMainApp
{
	/// <summary>
	/// ��ʼ�����л���
	/// </summary>
	void MainApplication::InitApp()
	{
		m_bRunning = true;
		bool ret = InitAllFunction();
		InitOpenGLWindows();
	}
	void MainApplication::Run()
	{
		m_pWindow->Show();
		while (m_bRunning)
		{
			m_pWindow->OnUpdate();
		}
	}
	/// <summary>
	/// �ͷ��������е���Դ
	/// </summary>
	void MainApplication::StopApp()
	{
		bool ret = StopAllFunction();

	}

	bool MainApplication::OnEvent(EventCommonNS::IEvent& e)
	{
		auto dispatchService = MdlCommonNS::ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_SysEventDriven_Type);
		EventDrivenSysNS::IDispatch* pDispathc = dispatchService.value()->ConvertType<EventDrivenSysNS::IDispatch*>();
		return pDispathc->DispatchEvent(e);//�����¼�  
	}
	/// <summary>
	/// ��ʼ������
	/// </summary>
	void MainApplication::InitOpenGLWindows()
	{
		auto windowsService = MdlCommonNS::ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_OpenGLWindow_Type);
		m_pWindow = windowsService.value()->ConvertType<WindowsNS::IWindow*>();
		m_pWindow->SetEventCallback(BIND_EVENT_FN(MainApplication::OnEvent));
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