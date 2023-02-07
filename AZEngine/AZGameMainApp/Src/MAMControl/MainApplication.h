#pragma once
#include "MACommon/CoreMacroDef.h"
#include "MdlCommon/Src/CMNMacro/CoreMacroDef.h"
namespace WindowsNS
{
	class IWindow;//窗口接口
}

namespace EventCommonNS
{
	class ISysEvent; //事件接口
	class WindowCloseEvent;
	class WindowResizeEvent;

}

namespace AZGameMainApp
{
	class EventService; //事件接口
}

namespace AZGameMainApp
{
	/// <summary>
	/// 游戏主程序，负责程序的初始化,启动、停止、资源释放
	/// 单例模式
	/// </summary>
	class MainApplication
	{
		//执行单例
		SingletonDefaultConstruct(MainApplication)
	public:
		void InitApp();//初始化程序
		void Run();//程序运行
		void StopApp();//停止程序
	private:
		bool OnEvent(EventCommonNS::ISysEvent& e);
	private:
		void InitOpenGLWindows();//初始化窗口
		void InitMember();//初始化陈远
		bool InitAllFunction();//初始化所有的功能模块并注册
		bool StopAllFunction();//停止所有的功能模块并取消注册
	//事件响应
	private:
		bool OnWindowCloseEvent(EventCommonNS::WindowCloseEvent& eve);
		bool OnWindowResizeEvent(EventCommonNS::WindowResizeEvent& eve);
	private:
		AZGameMainApp::EventService* m_pEveS;
		WindowsNS::IWindow* m_pWindow; //窗口
		bool m_bRunning;//程序是否运行
	};

}

