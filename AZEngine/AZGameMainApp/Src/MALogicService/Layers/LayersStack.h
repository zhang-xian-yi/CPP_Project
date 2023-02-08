#pragma once
#include <vector>

namespace LayerCommonNS
{
	//层数的接口
	class ILayer;
}

namespace AZGameMainApp
{
	//层数栈，分层响应事件和渲染界面
	class LayersStack
	{
	public:
		LayersStack() = default;
		~LayersStack();

		//层栈压入和弹出操作
		void PushLayer(LayerCommonNS::ILayer* layer);
		void PushOverlay(LayerCommonNS::ILayer* overlay);
		void PopLayer(LayerCommonNS::ILayer* layer);
		void PopOverlay(LayerCommonNS::ILayer* overlay);
		//层栈的访问操作
		std::vector<LayerCommonNS::ILayer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<LayerCommonNS::ILayer*>::iterator end() { return m_Layers.end(); }
		std::vector<LayerCommonNS::ILayer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		std::vector<LayerCommonNS::ILayer*>::reverse_iterator rend() { return m_Layers.rend(); }

		std::vector<LayerCommonNS::ILayer*>::const_iterator begin() const { return m_Layers.begin(); }
		std::vector<LayerCommonNS::ILayer*>::const_iterator end()	const { return m_Layers.end(); }
		std::vector<LayerCommonNS::ILayer*>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }
		std::vector<LayerCommonNS::ILayer*>::const_reverse_iterator rend() const { return m_Layers.rend(); }
	private:
		std::vector<LayerCommonNS::ILayer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};
}


