#include "TestBatchRenderRect3.h"
#include "Error/ErrorMacroDefie.h"
#include "imGui/imgui.h"
#include "Engines/DataLoadEnginePrivate.h"
#include "Engines/Layout/VertexBufferLayout.h"
#include "Render/TextureService.h"
namespace TestResNS
{
	TestBatchRenderRect3::TestBatchRenderRect3()
	{
		m_pRenderE = new RenderNS::RendererEngine();
		//��������
		float positionArray[] = {
			//������Ϊһ�����㣬0.5f ��ʾ��0~1�ķ�Χ��ռ��һ��
			//0.0f 0.0f ���������ʾ���½ǣ�1.0f,1.0f ��ʾ���Ͻ�
			//��0.1f ��ʼ�������Ƕ����RGBAֵ 
			//ǰ����folatֵ��������λ��,���ĸ�ֵ����������ɫ
			-0.75f,-0.5f,0.1f,0.6f,0.96f,1.0f,0.0f,0.0f,0.0f,
			-0.25f,-0.5f,0.1f,0.6f,0.96f,1.0f,1.0f,0.0f,0.0f,
			-0.25f,0.5f,0.1f,0.6f,0.96f,1.0f,1.0f,1.0f,	0.0f,
			-0.75f,0.5f,0.1f,0.6f,0.96f,1.0f,0.0f,1.0f,	0.0f,
			//�������� ����Ҫ�����仯��ͼ��ͨ������ת��ָ���Ķ�������
			//ͨ���Զ������ݵĽ����γɱ仯��Ч��
			0.25f,-0.5f,0.1f,0.93f,0.24f,1.0f,0.0f,0.0f, 1.0f,
			0.75f,-0.5f,0.1f,0.93f,0.24f,1.0f,1.0f,0.0f, 1.0f,
			0.75f,0.5f,0.1f,0.93f,0.24f,1.0f, 1.0f,1.0f, 1.0f,
			0.25f,0.5f,0.1f,0.93f,0.24f,1.0f, 0.0f,1.0f, 1.0f,
		};

		//����������
		unsigned int indices[] = {
			0,1,2,
			2,3,0,

			4,5,6,//��������
			6,7,4,//�������������
		};

		m_pShaderMng = new ShaderNS::ShaderManager();
		//��ʼ����ɫ������
		m_pShaderMng->initShader("/Resource/Shaders/BatchL/BatchVS3.shader", "/Resource/Shaders/BatchL/BatchFS3.shader");
		m_pShaderMng->Bind();
		int iArr[2] = { 0,1 };
		m_pShaderMng->SetUniform1iv("u_Textures", iArr,2);

		//�����Լ���������
		m_pTextureS = new RenderNS::TextureService();
		m_ATexSolt = m_pTextureS->LoadFileTexture("Resource/TexturesRes/flower.jpeg");
		m_BTexSolt = m_pTextureS->LoadFileTexture("Resource/TexturesRes/sky.jpeg");

		m_pRectDLE = new EngineNS::RectangleDataLoadEngine();
		m_pRectDLE->SetVertexData(positionArray, 9 * 8 * sizeof(float));
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
	TestBatchRenderRect3::~TestBatchRenderRect3()
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
	
	void TestBatchRenderRect3::onUpdate(float deltatime)
	{
		//����ÿ�θ���������ۺ����󶨵�������ȾID
		glBindTextureUnit(0, m_ATexSolt);
		glBindTextureUnit(1, m_BTexSolt);
	}
	void TestBatchRenderRect3::onRender()
	{

		m_pRenderE->Clear();//�������

		//ͨ������ָ�룬��ȡ������
		m_pRenderE->RendererDraw(m_pRectDLE->GetDataLoadEnginePointer(), m_pShaderMng);

	}
	void TestBatchRenderRect3::onImGUIRender()
	{
	}
}