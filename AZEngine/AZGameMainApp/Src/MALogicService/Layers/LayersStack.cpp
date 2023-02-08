#include "LayersStack.h"
#include "LayerCommon/Src/LCInterface/ILayer.h"
namespace AZGameMainApp
{
	LayersStack::~LayersStack()
	{
		for (LayerCommonNS::ILayer* layer : m_Layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayersStack::PushLayer(LayerCommonNS::ILayer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}

	void LayersStack::PushOverlay(LayerCommonNS::ILayer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayersStack::PopLayer(LayerCommonNS::ILayer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
		if (it != m_Layers.begin() + m_LayerInsertIndex)
		{
			layer->OnDetach();
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayersStack::PopOverlay(LayerCommonNS::ILayer* overlay)
	{
		auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			overlay->OnDetach();
			m_Layers.erase(it);
		}
	}
}