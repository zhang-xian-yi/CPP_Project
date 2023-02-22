#include "RendererServiceControl.h"
#include "ImguiRenderer/Src/IRLogiccService/ImGuiLayer.h"
namespace ImguiRendererNS
{
	RendererServiceControl::RendererServiceControl()
		:m_pImgui(nullptr)
	{
	}
	RendererServiceControl::~RendererServiceControl()
	{
	}
	LayerCommonNS::ILayer* RendererServiceControl::GetImguiRenderLayer()
	{
		if (m_pImgui == nullptr)
		{
			m_pImgui = new ImGuiLayer();
		}
		return m_pImgui;
	}
}