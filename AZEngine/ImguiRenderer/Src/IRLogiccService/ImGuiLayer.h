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
		virtual void OnImGuiRender() override;
		virtual void OnUpdate() override;

		void Begin();
		void End();
		void BlockEvents(bool block) { m_BlockEvents = block; }	
		void SetDarkThemeColors();
		unsigned int GetActiveWidgetID()const;
	private:
		bool m_BlockEvents = true;
	};

}
