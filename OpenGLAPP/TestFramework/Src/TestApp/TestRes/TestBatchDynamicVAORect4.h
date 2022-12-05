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
	class TestBatchDynamicVAORect4 : public TestNS::TestBase
	{
	public:
		TestBatchDynamicVAORect4();
		~TestBatchDynamicVAORect4();

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
		//图片A的
		float m_QAPosFArr[2] = { -1.3f,-0.9f };
		//图片A的
		float m_QBPosFArr[2] = { -0.9f,-2.6f };
	};

}

