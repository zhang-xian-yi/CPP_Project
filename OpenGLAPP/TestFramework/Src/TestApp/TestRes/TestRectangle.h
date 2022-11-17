#pragma once
#include "TestBase.h"
#include "Shader/ShaderManager.h"
#include "Engines/DataLoadEngine.h"
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
		EngineNS::DataLoadEngine* m_pDataLoad;
		//渲染引擎
		RenderNS::RendererEngine* m_pRenderE;
	};
}


