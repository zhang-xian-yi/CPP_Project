#pragma once
#include "MACommon/CoreMacroDef.h"
#include "MdlCommon/Src/CMNMacro/CoreMacroDef.h"
namespace WindowsNS
{
	class IWindow;//窗口接口
}

namespace LayerCommonNS
{
	class ISysEvent; //事件接口
	class WindowCloseEvent;
	class WindowResizeEvent;

}

namespace AZGameMainApp
{
	class EventService; //事件接口
	class LayersStack;
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
		bool OnEvent(LayerCommonNS::ISysEvent& e);
	private:
		void InitMember();//初始化
		bool InitAllFunction();//初始化所有的功能模块并注册
		bool StopAllFunction();//停止所有的功能模块并取消注册
	//事件响应
	private:
		bool OnWindowCloseEvent(LayerCommonNS::WindowCloseEvent& eve);
		bool OnWindowResizeEvent(LayerCommonNS::WindowResizeEvent& eve);
	private:
		AZGameMainApp::EventService* m_pEveS;
		WindowsNS::IWindow* m_pWindow; //窗口
		LayersStack* m_pLayersStack;
		bool m_bRunning;//程序是否运行
	};

}

