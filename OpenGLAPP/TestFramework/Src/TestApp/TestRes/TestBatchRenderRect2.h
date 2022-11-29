#pragma once
#include "TestBase.h"
#include "Shader/ShaderManager.h"
#include "Engines/RectangleDataLoadEngine.h"
#include "Render/RendererEngine.h"
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
	class TestBatchRenderRect2 : public TestNS::TestBase
	{
	public:
		TestBatchRenderRect2();
		~TestBatchRenderRect2();

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
	};

}
