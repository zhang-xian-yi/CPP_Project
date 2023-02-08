#pragma once

namespace LayerCommonNS
{
	class ISysEvent;
}

namespace LayerCommonNS
{
	//层数的接口
	class ILayer
	{
	public:
		ILayer() = default;
		virtual ~ILayer() = default;
	public:
		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnImGuiRender() = 0;
		virtual bool OnEvent(LayerCommonNS::ISysEvent& eve) = 0;
		virtual void OnUpdate() = 0;
	};
}