#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "OpenGLWindowUI/Src/IWindow.h"
namespace WindowsNS
{
	//ǰ������
	class OpenGLWindows;

	class WindowsServiceControl :public MdlCommonNS::IMdlService,public IWindow
	{
	public:
		WindowsServiceControl();
		~WindowsServiceControl();
	public://IWindow ���ؽӿ�
		void OnUpdate() override;

		unsigned int GetWidth() const override;
		unsigned int GetHeight() const override;
		//������ʾ
		virtual void Show()override;
		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override;
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const;
	private:
		MdlCommonNS::Scope<IWindow> m_pWin;
	};

}

