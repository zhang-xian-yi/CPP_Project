#pragma once
#include "OpenGLWindowUI/Src/IWindow.h"
#include "Service/GLWindowService.h"
#include "Service/SystemEventsService.h"
#include "WindowsData.h"
namespace EventCommonNS
{
	class WindowCloseEvent;
}

namespace WindowsNS
{
	/// <summary>
	/// OpenGL 实现的窗口
	/// </summary>
	class OpenGLWindows :public IWindow
	{
		//接口实现
	public:
		OpenGLWindows(const WindowProps& props);
		virtual ~OpenGLWindows();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_Data.WinPros.Width; }
		unsigned int GetHeight() const override { return m_Data.WinPros.Height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const { return m_pWinS->GetGLFWindowsHandle(); }
	public:
		virtual void Show()override;
		virtual void Shutdown();
	private:
		GLWindowService* m_pWinS; //GL窗口服务
		SystemEventsService* m_pSysEventS;
		WindowData m_Data;//窗口数据
	};
}