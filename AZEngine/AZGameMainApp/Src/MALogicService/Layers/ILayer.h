#pragma once

namespace EventCommonNS
{
	class IEvent;
}

namespace AZGameMainApp
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
		virtual bool OnEvent(const EventCommonNS::IEvent& eve) = 0;
		virtual void OnUpdate() = 0;
	};
}