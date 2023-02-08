#include "MainApplication.h"
#include <memory>//内存
#include "FunctionScheduling/Src/FuncScheduleFactory.h"//模块调度工厂
#include "FunctionScheduling/Src/IFuncSchedule.h"
#include "Logger/Src/ILogger.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNMEnum/Command/ECommand.h"//执行命令的参数
#include "EventDrivenSystem/Src/ISystemEvent.h"
#include "AZGameMainApp/Src/MALogicService/Events/EventService.h"
#include "LayerCommon/Src/SysEvents.h"
#include "OpenGLWindowUI/Src/IWindow.h" 
namespace AZGameMainApp
{
	/// <summary>
	/// 初始化运行环境
	/// </summary>
	void MainApplication::InitApp()
	{
		m_bRunning = true;
		bool ret = InitAllFunction();
		InitMember();//成员必须放在功能之后，窗口初始化之前，

		//注册窗口处理事件
		EventDrivenSysNS::EventResponseFunc<bool, LayerCommonNS::WindowCloseEvent&> winCloseEvent(BIND_EVENT_FN(MainApplication::OnWindowCloseEvent));
		m_pEveS->BindEventResponse(LayerCommonNS::ESysEventId::WindowClose, winCloseEvent);

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
	/// 释放允许环境中的资源
	/// </summary>
	void MainApplication::StopApp()
	{
		bool ret = StopAllFunction();

	}

	bool MainApplication::OnEvent(LayerCommonNS::ISysEvent& e)
	{
		bool ret = m_pEveS->HandleEvent(e);
		
		//TODO 分层的事件触发

		//返回时间分发结果
		return ret;
	}
	/// <summary>
	/// 初始化窗口
	/// </summary>
	void MainApplication::InitOpenGLWindows()
	{
		auto windowsService = MdlCommonNS::ServiceContainerSingle::GetInstance().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_OpenGLWindow_Type);
		m_pWindow = windowsService.value()->ConvertType<WindowsNS::IWindow*>();
		m_pWindow->SetEventCallback(BIND_EVENT_FN(MainApplication::OnEvent));
	}
	/// <summary>
	/// 初始化陈远
	/// </summary>
	void MainApplication::InitMember()
	{
		//初始化时间服务
		m_pEveS = new EventService();
	}
	/// <summary>
	/// 初始化所有的功能模块
	/// </summary>
	bool MainApplication::InitAllFunction()
	{
		auto factory = FuncScheduleNS::FuncScheduleFactory::GetFactory();
		auto pMdlScheduleCtl = factory->CreateModuleInstance();
		//初始化所有的功能模块-默认参数为空
		bool mdlInitRep = pMdlScheduleCtl->ConstructModule();
		auto pServiceScheduleCtl = factory->CreateServiceInstance();
		//注册模块
		MdlCommonNS::ServiceContainerSingle::GetInstance().RegisterModuleInterface(MdlCommonNS::EModuleType::E_FuncSchedule_Type, pMdlScheduleCtl, pServiceScheduleCtl);

		auto pService = pServiceScheduleCtl->ConvertType<FuncScheduleNS::IFuncSchedule*>();
		std::any mdlServiceRep = pService->ExecuteCmd(MdlCommonNS::ECommand::E_InitAllFunction);
		if (mdlServiceRep.has_value())
		{
			//返回初始化的响应并强制转换为bool 类型，确保初始化正常
			//响应与初始化完成正常
			std::tuple<bool, std::string> flag = std::any_cast<std::tuple<bool, std::string>>(mdlServiceRep);
			//必须确定flag的值之后才能返回
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
			//构造参数		
			std::any stopRep = pService->ExecuteCmd(MdlCommonNS::ECommand::E_DestoryAllFunction);
			//返回初始化的响应并强制转换为bool 类型，确保初始化正常
			std::tuple<bool, std::string> flag = std::any_cast<std::tuple<bool, std::string>>(stopRep);
			//必须确定flag的值之后才能返回
			return std::get<0>(flag);
		}
		return false;
	}
#pragma region 事件响应
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