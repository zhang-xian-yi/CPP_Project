#include "TestBatchDynamicVAORect4.h"
#include <array>
#include "Error/ErrorMacroDefie.h"
#include "imGui/imgui.h"
#include "Engines/DataLoadEnginePrivate.h"
#include "Engines/Buffers/VertexBuffer.h"
#include "Engines/Layout/VertexBufferLayout.h"
#include "Render/TextureService.h"


namespace BatchDynamicVAONS
{
	struct VecF2
	{
		float f1;
		float f2;
	};

	struct VecF3
	{
		float f1;
		float f2;
		float f3;
	};

	struct VecF4
	{
		float f1;
		float f2;
		float f3;
		float f4;
	};

	//���嶥��
	struct TVertex
	{
		VecF2 position;//λ��
		VecF4 Color;//����
		VecF2 TexCoord;//��������
		float TexID;//����ۺ�
	};

	static std::array<TVertex, 4> CreateQuadrangle(float x, float y, float texID)
	{
		size_t Vsize = 1.0f;//����֮��ľ���

		TVertex tv0;
		tv0.position = {x,y};
		tv0.Color = { 0.1f,0.6f,0.96f,1.0f };
		tv0.TexCoord = {0.0f,0.0f};
		tv0.TexID = texID;

		TVertex tv1;
		tv1.position = { x + Vsize,y };
		tv1.Color = { 0.1f,0.6f,0.96f,1.0f };
		tv1.TexCoord = { 1.0f,0.0f };
		tv1.TexID = texID;

		TVertex tv2;
		tv2.position = { x +Vsize,y + Vsize };
		tv2.Color = { 0.1f,0.6f,0.96f,1.0f };
		tv2.TexCoord = { 1.0f,1.0f };
		tv2.TexID = texID;

		TVertex tv3;
		tv3.position = { x,y+Vsize };
		tv3.Color = { 0.1f,0.6f,0.96f,1.0f };
		tv3.TexCoord = { 0.0f,1.0f };
		tv3.TexID = texID;
		return { tv0 ,tv1 ,tv2 ,tv3 };
	}

}

namespace TestResNS
{

	TestBatchDynamicVAORect4::TestBatchDynamicVAORect4()
	{
		m_pRenderE = new RenderNS::RendererEngine();

		m_pShaderMng = new ShaderNS::ShaderManager();
		//��ʼ����ɫ������
		m_pShaderMng->initShader("/Resource/Shaders/BatchL/BatchVS3.shader", "/Resource/Shaders/BatchL/BatchFS3.shader");
		m_pShaderMng->Bind();
		int iArr[2] = { 0,1 };
		m_pShaderMng->SetUniform1iv("u_Textures", iArr, 2);

		//�����Լ���������
		m_pTextureS = new RenderNS::TextureService();
		m_ATexSolt = m_pTextureS->LoadFileTexture("Resource/TexturesRes/flower.jpeg");
		m_BTexSolt = m_pTextureS->LoadFileTexture("Resource/TexturesRes/sky.jpeg");

		m_pRectDLE = new EngineNS::RectangleDataLoadEngine();
		auto pDataLoadE = m_pRectDLE->GetDataLoadEnginePointer();
		auto pVBufS = pDataLoadE->GetVertexBufferPointer();
		//����һ��100 ������Ļ�����
		pVBufS->SetDynamicVertexData(nullptr, sizeof(BatchDynamicVAONS::TVertex) * 100);
		//����������
		unsigned int indices[] = {
			0,1,2,
			2,3,0,

			4,5,6,//��������
			6,7,4,//�������������
		};

		m_pRectDLE->SetIndexData(indices, 12);
		//��ʼ�����ݻ���
		//�˴����㻺�������ֵ�push  �붥��shader�ļ��е�layout�����
		LayoutNS::VertexBufferLayout* pVBufLayout = m_pRectDLE->GetDataLoadEnginePointer()->GetVBufLayoutPointer();
		//�Ҵ����Ⱥ�˳���ϵ
		pVBufLayout->Push<float>(2);//2��������������������
		pVBufLayout->Push<float>(4);//4������������������ɫ
		pVBufLayout->Push<float>(2);//2��������������������
		pVBufLayout->Push<float>(1);//1����������������ۺ�����
		//�������㻺�����Ͷ��㲼�ֶ���Ĺ�ϵ
		m_pRectDLE->GetDataLoadEnginePointer()->BindVBuffAndVLayout();

	}
	TestBatchDynamicVAORect4::~TestBatchDynamicVAORect4()
	{
		if (m_pTextureS == nullptr)
		{
			delete m_pTextureS;
			m_pTextureS = nullptr;
		}

		if (m_pRenderE == nullptr)
		{
			delete m_pRenderE;
			m_pRenderE = nullptr;
		}

		if (m_pRectDLE == nullptr)
		{
			delete m_pRectDLE;
			m_pRectDLE = nullptr;
		}

		if (m_pShaderMng == nullptr)
		{
			delete m_pShaderMng;
			m_pShaderMng = nullptr;
		}
	}

	void TestBatchDynamicVAORect4::onUpdate(float deltatime)
	{
		//����ÿ�θ���������ۺ����󶨵�������ȾID
		glBindTextureUnit(0, m_ATexSolt);//��
		glBindTextureUnit(1, m_BTexSolt);//�ǿ�

		auto q0 = BatchDynamicVAONS::CreateQuadrangle(m_QAPosFArr[0], m_QAPosFArr[1], 0.0f);
		auto q1 = BatchDynamicVAONS::CreateQuadrangle(m_QBPosFArr[0], m_QBPosFArr[1], 1.0f);
		//����˸����������
		BatchDynamicVAONS::TVertex TVertexs[8];

		memcpy(TVertexs, q0.data(), q0.size() * sizeof(BatchDynamicVAONS::TVertex));
		memcpy(TVertexs + q0.size(), q1.data(), q1.size() * sizeof(BatchDynamicVAONS::TVertex));
		//�˷������Ըı䶥�㻺���������ݣ� Ҳ������glmapbuffer
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(TVertexs), TVertexs);
	
	}
	void TestBatchDynamicVAORect4::onRender()
	{

		m_pRenderE->Clear();//�������

		//ͨ������ָ�룬��ȡ������
		m_pRenderE->RendererDraw(m_pRectDLE->GetDataLoadEnginePointer(), m_pShaderMng);

	}

	//Imgui

	void TestBatchDynamicVAORect4::onImGUIRender()
	{
		ImGui::DragFloat2("ControlA",m_QAPosFArr,0.1f);
		ImGui::Separator();
		ImGui::DragFloat2("ControlB", m_QBPosFArr, 0.1f);
	}
}