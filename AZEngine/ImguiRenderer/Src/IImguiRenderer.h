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
		virtual ~IImguiRenderer() = 0;//����������

	public:
		//��ȡImguiRenderer�Ĳ�ָ��
		LayerCommonNS::ILayer* GetImguiRenderLayer() = 0;
	};
}