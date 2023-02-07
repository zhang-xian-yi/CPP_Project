#include "MainApplication.h"
#include <memory>//�ڴ�
#include "FunctionScheduling/Src/FuncScheduleFactory.h"//ģ����ȹ���
#include "FunctionScheduling/Src/IFuncSchedule.h"
#include "Logger/Src/ILogger.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNMEnum/Command/ECommand.h"//ִ������Ĳ���
#include "EventDrivenSystem/Src/ISystemEvent.h"
#include "AZGameMainApp/Src/MALogicService/Events/EventService.h"
#include "EventCommon/Src/SysEvents.h"
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
		InitMember();//��Ա������ڹ���֮�󣬴��ڳ�ʼ��֮ǰ��

		//ע�ᴰ�ڴ����¼�
		EventDrivenSysNS::EventResponseFunc<bool, EventCommonNS::WindowCloseEvent&> winCloseEvent(BIND_EVENT_FN(MainApplication::OnWindowCloseEvent));
		m_pEveS->BindEventResponse(EventCommonNS::ESysEventId::WindowClose, winCloseEvent);

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

	bool MainApplication::OnEvent(EventCommonNS::ISysEvent& e)
	{
		bool ret = m_pEveS->HandleEvent(e);
		
		//TODO �ֲ���¼�����

		//����ʱ��ַ����
		return ret;
	}
	/// <summary>
	/// ��ʼ������
	/// </summary>
	void MainApplication::InitOpenGLWindows()
	{
		auto windowsService = MdlCommonNS::ServiceContainerSingle::GetInstance().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_OpenGLWindow_Type);
		m_pWindow = windowsService.value()->ConvertType<WindowsNS::IWindow*>();
		m_pWindow->SetEventCallback(BIND_EVENT_FN(MainApplication::OnEvent));
	}
	/// <summary>
	/// ��ʼ����Զ
	/// </summary>
	void MainApplication::InitMember()
	{
		//��ʼ��ʱ�����
		m_pEveS = new EventService();
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
		MdlCommonNS::ServiceContainerSingle::GetInstance().RegisterModuleInterface(MdlCommonNS::EModuleType::E_FuncSchedule_Type, pMdlScheduleCtl, pServiceScheduleCtl);

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
		auto pServiceOptional = MdlCommonNS::ServiceContainerSingle::GetInstance().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_FuncSchedule_Type);
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
#pragma region �¼���Ӧ
	bool MainApplication::OnWindowCloseEvent(EventCommonNS::WindowCloseEvent& eve)
	{
		m_bRunning = false;
		return false;
	}
	bool MainApplication::OnWindowResizeEvent(EventCommonNS::WindowResizeEvent& eve)
	{
		/*
		if (eve.GetWidth() == 0 || eve.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
		*/
		return true;
	}
#pragma endregion
}