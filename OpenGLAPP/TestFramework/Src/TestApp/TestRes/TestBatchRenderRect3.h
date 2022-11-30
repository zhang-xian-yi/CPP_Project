#pragma once
#include "TestBase.h"
#include "Shader/ShaderManager.h"
#include "Engines/RectangleDataLoadEngine.h"
#include "Render/RendererEngine.h"
#include "Render/TextureService.h"
/*
����Ⱦ��˼�� ʱ��һ֡�����г��ֵļ���ͼ��
ȫ�����붥�㻺������ͳһ������Ⱦ
������  ��һ��DrawCall �� ��Ⱦ���ͼ��

*/

namespace TestResNS
{
	/// <summary>
	/// ����������Ⱦ�������ε�ҵ���߼�
	/// </summary>
	class TestBatchRenderRect3 : public TestNS::TestBase
	{
	public:
		TestBatchRenderRect3();
		~TestBatchRenderRect3();

		//����
		void onUpdate(float deltatime) override;
		void onRender() override;
		void onImGUIRender() override;

	private:
		//��ɫ��
		ShaderNS::ShaderManager* m_pShaderMng;
		//���ݼ�������
		EngineNS::RectangleDataLoadEngine* m_pRectDLE;
		//��Ⱦ����
		RenderNS::RendererEngine* m_pRenderE;
		//������ع���
		RenderNS::TextureService* m_pTextureS;

		//���ص�����ۺ�
		int m_ATexSolt, m_BTexSolt;
	};

}
