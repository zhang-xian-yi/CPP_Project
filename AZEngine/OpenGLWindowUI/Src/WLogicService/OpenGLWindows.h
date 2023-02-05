#pragma once
#include "OpenGLWindowUI/Src/IWindow.h"

struct GLFWwindow;// ǰ������ ����glew

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

		unsigned int GetWidth() const override { return m_Data.Width; }
		unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const { return m_Window; }
	public:
		virtual void Show()override;
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		//��������
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}