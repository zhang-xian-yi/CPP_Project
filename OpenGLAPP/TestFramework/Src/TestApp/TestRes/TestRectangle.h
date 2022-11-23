#pragma once
#include "TestBase.h"
#include "Shader/ShaderManager.h"
#include "Engines/RectangleDataLoadEngine.h"
#include "Render/RendererEngine.h"
namespace TestResNS
{
	//测试
	class TestRectangle : public TestNS::TestBase
	{
	public:
		TestRectangle();
		~TestRectangle();

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


