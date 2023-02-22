#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "ImguiRenderer/Src/IImguiRenderer.h"
namespace ImguiRendererNS
{
	class ImGuiLayer;

	//
	class RendererServiceControl:public MdlCommonNS::IMdlService,public ImguiRendererNS::IImguiRenderer
	{
	public:
		RendererServiceControl();
		~RendererServiceControl();
	public:
		virtual LayerCommonNS::ILayer* GetImguiRenderLayer()override;
	private:
		ImGuiLayer* m_pImgui;
	};
}

