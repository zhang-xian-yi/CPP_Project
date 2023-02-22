#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "IWindow.h"
namespace WindowsNS
{
	//前置声明
	class OpenGLWindows;

	class WindowsServiceControl :public MdlCommonNS::IMdlService,public IWindow
	{
	public:
		WindowsServiceControl();
		~WindowsServiceControl();
	public://IWindow 重载接口
		LayerCommonNS::ILayer* GetOpenGLWindowLayer() override;

		unsigned int GetWidth() const override;
		unsigned int GetHeight() const override;
		//窗口显示
		virtual void Show()override;
		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override;

		virtual void* GetNativeWindow() const;
	private:
		OpenGLWindows* m_pWin;
		LayerCommonNS::ILayer* m_pLayer;
	};

}

