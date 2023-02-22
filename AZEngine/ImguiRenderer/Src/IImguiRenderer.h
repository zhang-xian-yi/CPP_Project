#pragma once
#include "IRCommon/IRExpMarcoDefine.h"
namespace LayerCommonNS
{
	class ILayer;
}

namespace ImguiRendererNS
{
	class ImguiRendererNSAPI IImguiRenderer
	{
	public:
		virtual ~IImguiRenderer() {};//虚析构函数

	public:
		//获取ImguiRenderer的层指针
		virtual LayerCommonNS::ILayer* GetImguiRenderLayer() = 0;
	};
}