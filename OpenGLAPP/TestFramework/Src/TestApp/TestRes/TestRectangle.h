#pragma once
#include "TestBase.h"
#include "Shader/ShaderManager.h"
#include "Engines/DataLoadEngine.h"
#include "Render/RendererEngine.h"
namespace TestResNS
{
	//����
	class TestRectangle : public TestNS::TestBase
	{
	public:
		TestRectangle();
		~TestRectangle();

		//����
		void onUpdate(float deltatime) override;
		void onRender() override;
		void onImGUIRender() override;

	private:
		//��ɫ��
		ShaderNS::ShaderManager* m_pShaderMng;
		//���ݼ�������
		EngineNS::DataLoadEngine* m_pDataLoad;
		//��Ⱦ����
		RenderNS::RendererEngine* m_pRenderE;
	};
}


