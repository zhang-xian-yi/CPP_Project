#pragma once

#include "LayerCommon/Src/LCInterface/ILayer.h"
namespace ImguiRendererNS {

	class ImGuiLayer : public LayerCommonNS::ILayer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual bool OnEvent(LayerCommonNS::ISysEvent& e) override;
		virtual void OnRender() override;
		virtual void OnUpdate() override;
	private:
		void Begin();
		void End();
		void BlockEvents(bool block) { m_BlockEvents = block; }	
		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
	};

}
