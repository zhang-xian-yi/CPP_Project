#pragma once

#include <string>
#include "TestBase.h"

#include "Shader/ShaderManager.h"
#include "Engines/TextureDataLoadEngine.h"
#include "Render/RendererEngine.h"
#include "Render/TextureService.h"
namespace TestResNS
{
	/// <summary>
	/// 纹理的测试
	/// </summary>
	class TestTexture2D : public TestNS::TestBase
	{
	public:
		TestTexture2D();
		~TestTexture2D();

		//动画
		void onUpdate(float deltatime) override;
		//显示的渲染
		void onRender() override;
		//界面的触发和响应
		void onImGUIRender() override;

	private:
		//着色器
		ShaderNS::ShaderManager* m_pShaderMng;
		//纹理的数据加载引擎
		EngineNS::TextureDataLoadEngine* m_pTextureDLE;
		//渲染引擎
		RenderNS::RendererEngine* m_pRenderE;
		//纹理的加载和操作
		RenderNS::TextureService* m_pTextureS;

		//模型矩阵，xyz 三轴，x轴正向200，Y轴正向100单位，Z轴上不同
		glm::vec3 m_ModelAVec3;
		glm::vec3 m_ModelBVec3;
	};

}


