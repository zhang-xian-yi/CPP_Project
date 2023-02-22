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
#include "AZGameMainApp/Src/MALogicService/Layers/LayersStack.h"//��ջ
#include "LayerCommon/Src/LCInterface/ILayer.h"//��ջָ��
#include "LayerCommon/Src/SysEvents.h"
#include "OpenGLWindowUI/Src/IWindow.h" 
#include "ImguiRenderer/Src/IImguiRenderer.h"
#include "OpenGLWindowUI/Src/IWindow.h"
namespace AZGameMainApp
{
	/// <summary>
	/// ��ʼ�����л���
	/// </summary>
	void MainApplication::InitApp()
	{
		m_bRunning = true;
		InitAllFunction();
		InitMember();
		//ע�ᴰ�ڴ����¼�
		EventDrivenSysNS::EventResponseFunc<bool, LayerCommonNS::WindowCloseEvent&> winCloseEvent(BIND_EVENT_FN(MainApplication::OnWindowCloseEvent));
		m_pEveS->BindEventResponse(LayerCommonNS::ESysEventId::WindowClose, winCloseEvent);

	}
	void MainApplication::Run()
	{
		while (m_bRunning)
		{
			//�ӵ��򶥿�ʼ����
			for (LayerCommonNS::ILayer* layer : *m_pLayersStack)
			{
				layer->OnUpdate();
			}
			//�ӵ��򶥿�ʼ��Ⱦ
			for (LayerCommonNS::ILayer* layer : *m_pLayersStack)
			{
				layer->OnRender();
			}
		}
	}
	/// <summary>
	/// �ͷ��������е���Դ
	/// </summary>
	void MainApplication::StopApp()
	{
		bool ret = StopAllFunction();

	}

	bool MainApplication::OnEvent(LayerCommonNS::ISysEvent& e)
	{
		bool ret = m_pEveS->HandleEvent(e);
		
		//TODO �ֲ���¼����� �Ӷ��㵽�ײ������Ӧ�¼�
		for (auto it = m_pLayersStack->rbegin(); it != m_pLayersStack->rend(); ++it)
		{
			ret = (*it)->OnEvent(e);
			//�����Ӧ�¼�
			if (ret)
			{
				break;//�¼��ѱ�����������������
			}
		}
		//����ʱ��ַ����
		return ret;
	}
	/// <summary>
	/// ��ʼ����Զ
	/// </summary>
	void MainApplication::InitMember()
	{
		//��ʼ��ʱ�����
		m_pEveS = new EventService();
		m_pLayersStack = new LayersStack();

		//��ʼ��OPenGL���ڲ�
		auto iOWS = MdlCommonNS::ServiceContainerSingle::GetInstance().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_OpenGLWindow_Type);
		auto OW = iOWS.value()->ConvertType<WindowsNS::IWindow*>();
		OW->GetOpenGLWindowLayer()->OnAttach();
		OW->SetEventCallback(BIND_EVENT_FN(MainApplication::OnEvent));//�����¼�����ص�����
		//��ʼ��Imgui ��
		auto iIRS = MdlCommonNS::ServiceContainerSingle::GetInstance().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_ImguiRenderer_Type);
		auto IR = iIRS.value()->ConvertType<ImguiRendererNS::IImguiRenderer*>();
		IR->GetImguiRenderLayer()->OnAttach();

		//ȷ���Ƚ����
		m_pLayersStack->PushLayer(OW->GetOpenGLWindowLayer());//���ڲ�ջ��
		m_pLayersStack->PushLayer(IR->GetImguiRenderLayer());//imgui�ڴ��ڲ�֮��
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
	bool MainApplication::OnWindowCloseEvent(LayerCommonNS::WindowCloseEvent& eve)
	{
		m_bRunning = false;
		return false;
	}
	bool MainApplication::OnWindowResizeEvent(LayerCommonNS::WindowResizeEvent& eve)
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