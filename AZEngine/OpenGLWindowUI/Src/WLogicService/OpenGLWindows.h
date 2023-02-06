#pragma once
#include "OpenGLWindowUI/Src/IWindow.h"
#include "Service/GLWindowService.h"

namespace WindowsNS
{
	/// <summary>
	/// OpenGL 实现的窗口
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

		//窗口数据
		struct WindowData
		{
			WindowProps WinPros;//窗口属性
			bool VSync;
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}