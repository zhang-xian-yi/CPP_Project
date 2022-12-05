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

	/// <summary>
	/// ����ָ����С����������
	/// </summary>
	/// <param name="target"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="texID"></param>
	/// <returns></returns>
	static TVertex* CreateQuadrangle(TVertex* target,float x, float y, float texID)
	{
		float Vsize = 1.0f;//����֮��ľ���

		target->position = {x,y};
		target->Color = { 0.1f,0.6f,0.96f,1.0f };
		target->TexCoord = {0.0f,0.0f};
		target->TexID = texID;
		target++;//ָ������ �Ⱥ�ƫ�� sizeof(TVertex)��С���ֽ��� Ϊ�¶�����ʼ��ַ

		target->position = { x + Vsize,y };
		target->Color = { 0.1f,0.6f,0.96f,1.0f };
		target->TexCoord = { 1.0f,0.0f };
		target->TexID = texID;
		target++;//ָ������ �Ⱥ�ƫ�� sizeof(TVertex)��С���ֽ��� Ϊ�¶�����ʼ��ַ

		target->position = { x +Vsize,y + Vsize };
		target->Color = { 0.1f,0.6f,0.96f,1.0f };
		target->TexCoord = { 1.0f,1.0f };
		target->TexID = texID;
		target++;//ָ������ �Ⱥ�ƫ�� sizeof(TVertex)��С���ֽ��� Ϊ�¶�����ʼ��ַ

		target->position = { x,y+Vsize };
		target->Color = { 0.1f,0.6f,0.96f,1.0f };
		target->TexCoord = { 0.0f,1.0f };
		target->TexID = texID;
		target++;//ָ������ �Ⱥ�ƫ�� sizeof(TVertex)��С���ֽ��� Ϊ�¶�����ʼ��ַ

		return target;
	}

}

namespace TestResNS
{
	static const size_t SMaxQuadCount = 25; // ��Ļ������ı��θ���
	static const  size_t SMaxVertexCount = SMaxQuadCount * 4;//��󶥵����
	static const size_t SMaxIndexCount = SMaxQuadCount * 6;//�����������


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
		pVBufS->SetDynamicVertexData(nullptr, sizeof(BatchDynamicVAONS::TVertex) * SMaxVertexCount);
		/*
		//����������
		unsigned int indices[] = {
			0,1,2,2,3,0,			
			//��������
			4,5,6,6,7,4,//�������������			
		};
		*/
		//
		unsigned int indices[SMaxIndexCount];
		//�����������������ģʽ
		unsigned int offset = 0;//һ���ı���ƫ��һ��
		for (unsigned int i = 0; i < SMaxIndexCount; i+=6)
		{
			indices[i] = 0 + offset;
			indices[i + 1] = 1 + offset;
			indices[i + 2] = 2 + offset;

			indices[i + 3] = 2 + offset;
			indices[i + 4] = 3 + offset;
			indices[i + 5] = 0 + offset;

			offset += 4;//ÿ���ı������������㣬�����һ��
		}


		m_pRectDLE->SetIndexData(indices, SMaxIndexCount);
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


		std::array<BatchDynamicVAONS::TVertex, 100> verterxArr;//���嶥����
		BatchDynamicVAONS::TVertex* buffer = verterxArr.data();//��ȡ������ʼָ��
		for (int y = 0; y <= 3; y++)
		{
			for (int x = 0; x <= 3; x++)
			{
				if ((x + y) % 2 == 0)
				{
					buffer = BatchDynamicVAONS::CreateQuadrangle(buffer, x + m_QAPosFArr[0], y + m_QAPosFArr[1], (x + y) % 2);
				}
				else
				{
					buffer = BatchDynamicVAONS::CreateQuadrangle(buffer, x + m_QBPosFArr[0], y + m_QBPosFArr[1], (x + y) % 2);
				}
			}
		}
		//�����������Ա����Ƶ�ͼ��
		buffer = BatchDynamicVAONS::CreateQuadrangle(buffer,m_QAPosFArr[0], m_QAPosFArr[1], 0.0f);

		buffer = BatchDynamicVAONS::CreateQuadrangle(buffer,m_QBPosFArr[0], m_QBPosFArr[1], 1.0f);

		//�˷������Ըı䶥�㻺���������ݣ� Ҳ������glmapbuffer
		glBufferSubData(GL_ARRAY_BUFFER, 0, verterxArr.size() * sizeof(BatchDynamicVAONS::TVertex), verterxArr.data());
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