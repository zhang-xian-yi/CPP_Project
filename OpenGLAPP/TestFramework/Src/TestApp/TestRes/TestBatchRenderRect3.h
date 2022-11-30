#pragma once
#include "TestBase.h"
#include "Shader/ShaderManager.h"
#include "Engines/RectangleDataLoadEngine.h"
#include "Render/RendererEngine.h"
#include "Render/TextureService.h"
/*
批渲染的思想 时将一帧中所有出现的几何图形
全部放入顶点缓冲区，统一进行渲染
核心是  再一次DrawCall 中 渲染多个图形

*/

namespace TestResNS
{
	/// <summary>
	/// 测试批量渲染的正方形的业务逻辑
	/// </summary>
	class TestBatchRenderRect3 : public TestNS::TestBase
	{
	public:
		TestBatchRenderRect3();
		~TestBatchRenderRect3();

		//更新
		void onUpdate(float deltatime) override;
		void onRender() override;
		void onImGUIRender() override;

	private:
		//着色器
		ShaderNS::ShaderManager* m_pShaderMng;
		//数据加载引擎
		EngineNS::RectangleDataLoadEngine* m_pRectDLE;
		//渲染引擎
		RenderNS::RendererEngine* m_pRenderE;
		//纹理加载工具
		RenderNS::TextureService* m_pTextureS;

		//加载的纹理槽号
		int m_ATexSolt, m_BTexSolt;
	};

}
