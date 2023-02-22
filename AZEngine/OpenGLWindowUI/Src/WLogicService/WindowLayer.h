#pragma once
#include "LayerCommon/Src/LCInterface/ILayer.h"
#include "WLogicService/OpenGLWindows.h"
namespace WindowsNS
{
	class WindowLayer :public LayerCommonNS::ILayer
	{
	public:
		WindowLayer(OpenGLWindows* win);
		~WindowLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual bool OnEvent(LayerCommonNS::ISysEvent & e) override;
		virtual void OnRender() override;
		virtual void OnUpdate() override;
	private:
		void Begin();
		void End();
		void SetDarkThemeColors();
	private:
		OpenGLWindows* m_pWin;
	};

}

