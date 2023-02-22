#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "IWindow.h"
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
		LayerCommonNS::ILayer* GetOpenGLWindowLayer() override;

		unsigned int GetWidth() const override;
		unsigned int GetHeight() const override;
		//������ʾ
		virtual void Show()override;
		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override;

		virtual void* GetNativeWindow() const;
	private:
		OpenGLWindows* m_pWin;
		LayerCommonNS::ILayer* m_pLayer;
	};

}

