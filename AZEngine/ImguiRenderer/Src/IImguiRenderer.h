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
		virtual ~IImguiRenderer() {};//����������

	public:
		//��ȡImguiRenderer�Ĳ�ָ��
		virtual LayerCommonNS::ILayer* GetImguiRenderLayer() = 0;
	};
}