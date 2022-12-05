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
	class TestBatchDynamicVAORect4 : public TestNS::TestBase
	{
	public:
		TestBatchDynamicVAORect4();
		~TestBatchDynamicVAORect4();

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
		//ͼƬA��
		float m_QAPosFArr[2] = { -1.3f,-0.9f };
		//ͼƬA��
		float m_QBPosFArr[2] = { -0.9f,-2.6f };
	};

}

