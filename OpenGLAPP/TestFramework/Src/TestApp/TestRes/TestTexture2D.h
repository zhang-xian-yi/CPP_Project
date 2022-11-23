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
	/// ����Ĳ���
	/// </summary>
	class TestTexture2D : public TestNS::TestBase
	{
	public:
		TestTexture2D();
		~TestTexture2D();

		//����
		void onUpdate(float deltatime) override;
		//��ʾ����Ⱦ
		void onRender() override;
		//����Ĵ�������Ӧ
		void onImGUIRender() override;

	private:
		//��ɫ��
		ShaderNS::ShaderManager* m_pShaderMng;
		//��������ݼ�������
		EngineNS::TextureDataLoadEngine* m_pTextureDLE;
		//��Ⱦ����
		RenderNS::RendererEngine* m_pRenderE;
		//����ļ��غͲ���
		RenderNS::TextureService* m_pTextureS;

		//ģ�;���xyz ���ᣬx������200��Y������100��λ��Z���ϲ�ͬ
		glm::vec3 m_ModelAVec3;
		glm::vec3 m_ModelBVec3;
	};

}


