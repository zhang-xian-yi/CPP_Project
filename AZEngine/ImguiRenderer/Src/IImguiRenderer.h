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
		virtual ~IImguiRenderer() {};//����������

	public:
		//��ȡImguiRenderer�Ĳ�ָ��
		virtual LayerCommonNS::ILayer* GetImguiRenderLayer() = 0;
		//��Ⱦ��ʼ�ͽ���
		virtual void Begin() = 0;
		virtual void End() = 0;
	};
}