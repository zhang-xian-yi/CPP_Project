#pragma once
namespace LayerCommonNS
{
	class ILayer;
}

namespace ImguiRendererNS
{
	class IImguiRenderer
	{
	public:
		virtual ~IImguiRenderer() = 0;//虚析构函数

	public:
		//获取ImguiRenderer的层指针
		LayerCommonNS::ILayer* GetImguiRenderLayer() = 0;
	};
}