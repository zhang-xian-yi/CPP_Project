#pragma once
#include "IWindow.h"
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
	class OpenGLWindows
	{
		//�ӿ�ʵ��
	public:
		OpenGLWindows(const WindowProps& props);
		virtual ~OpenGLWindows();

		void OnUpdate();

		unsigned int GetWidth() const { return m_Data.WinPros.Width; }
		unsigned int GetHeight() const { return m_Data.WinPros.Height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled);
		bool IsVSync() const;

		virtual void* GetNativeWindow() const { return m_pWinS->GetGLFWindowsHandle(); }
	public:
		virtual void Show();
		virtual void Shutdown();
	private:
		GLWindowService* m_pWinS; //GL���ڷ���
		SystemEventsService* m_pSysEventS;
		WindowData m_Data;//��������
	};
}