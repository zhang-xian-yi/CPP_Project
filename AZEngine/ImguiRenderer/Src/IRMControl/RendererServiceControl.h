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
		//渲染开始和结束
		virtual void Begin() override;
		virtual void End() override;
	private:
		ImGuiLayer* m_pImgui;
	};
}

