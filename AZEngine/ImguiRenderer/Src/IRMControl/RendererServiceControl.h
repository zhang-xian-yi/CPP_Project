#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "ImguiRenderer/Src/IImguiRenderer.h"
namespace ImguiRendererNS
{
	//
	class RendererServiceControl:MdlCommonNS::IMdlService, ImguiRendererNS::IImguiRenderer
	{
	public:
		RendererServiceControl();
		~RendererServiceControl();
	public:
		virtual LayerCommonNS::ILayer* GetImguiRenderLayer()override;
	};
}

