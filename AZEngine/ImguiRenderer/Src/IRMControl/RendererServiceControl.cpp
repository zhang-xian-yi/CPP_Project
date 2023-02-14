#include "RendererServiceControl.h"
#include "ImguiRenderer/Src/IRLogiccService/ImGuiLayer.h"
namespace ImguiRendererNS
{
	RendererServiceControl::RendererServiceControl()
	{
	}
	RendererServiceControl::~RendererServiceControl()
	{
	}
	LayerCommonNS::ILayer* RendererServiceControl::GetImguiRenderLayer()
	{
		return new ImGuiLayer();
	}
}