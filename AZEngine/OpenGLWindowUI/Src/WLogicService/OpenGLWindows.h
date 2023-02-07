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
	/// OpenGL ʵ�ֵĴ���
	/// </summary>
	class OpenGLWindows :public IWindow
	{
		//�ӿ�ʵ��
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
		GLWindowService* m_pWinS; //GL���ڷ���
		SystemEventsService* m_pSysEventS;
		WindowData m_Data;//��������
	};
}