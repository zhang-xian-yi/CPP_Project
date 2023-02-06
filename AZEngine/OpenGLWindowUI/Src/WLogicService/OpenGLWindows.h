#pragma once
#include "OpenGLWindowUI/Src/IWindow.h"
#include "Service/GLWindowService.h"

namespace WindowsNS
{
	/// <summary>
	/// OpenGL ʵ�ֵĴ���
	/// </summary>
	class OpenGLWindows :public IWindow
	{
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

		virtual void* GetNativeWindow() const { return m_WinService->GetGLFWindowsHandle(); }
	public:
		virtual void Show()override;
		virtual void Shutdown();
	private:
		GLWindowService* m_WinService;

		//��������
		struct WindowData
		{
			WindowProps WinPros;//��������
			bool VSync;
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}