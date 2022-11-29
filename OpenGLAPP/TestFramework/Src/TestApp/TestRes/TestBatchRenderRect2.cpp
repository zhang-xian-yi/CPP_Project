#include "TestBatchRenderRect2.h"
#include "Error/ErrorMacroDefie.h"
#include "imGui/imgui.h"
#include "Engines/DataLoadEnginePrivate.h"
#include "Engines/Layout/VertexBufferLayout.h"
namespace TestResNS
{
	TestBatchRenderRect2::TestBatchRenderRect2()
	{

		m_pRenderE = new RenderNS::RendererEngine();
		m_pShaderMng = new ShaderNS::ShaderManager();
		//��ʼ����ɫ������
		m_pShaderMng->initShader("/Resource/Shaders/BatchL/Vertex.shader", "/Resource/Shaders/BatchL/Fragment.shader");
		m_pShaderMng->Bind();

		//��������
		float positionArray[] = {
			//������Ϊһ�����㣬0.5f ��ʾ��0~1�ķ�Χ��ռ��һ��
			//0.0f 0.0f ���������ʾ���½ǣ�1.0f,1.0f ��ʾ���Ͻ�
			//��0.1f ��ʼ�������Ƕ����RGBAֵ 
			//ǰ����folatֵ��������λ��,���ĸ�ֵ����������ɫ
			-0.75f,-0.5f,0.1f,0.6f,0.96f,1.0f,
			-0.25f,-0.5f,0.1f,0.6f,0.96f,1.0f,
			-0.25f,0.5f,0.1f,0.6f,0.96f,1.0f,
			-0.75f,0.5f,0.1f,0.6f,0.96f,1.0f,
			//�������� ����Ҫ�����仯��ͼ��ͨ������ת��ָ���Ķ�������
			//ͨ���Զ������ݵĽ����γɱ仯��Ч��
			0.25f,-0.5f,0.1f,0.93f,0.24f,1.0f,
			0.75f,-0.5f,0.1f,0.93f,0.24f,1.0f,
			0.75f,0.5f,0.1f,0.93f,0.24f,1.0f,
			0.25f,0.5f,0.1f,0.93f,0.24f,1.0f,
		};

		//����������
		unsigned int indices[] = {
			0,1,2,
			2,3,0,

			4,5,6,//��������
			6,7,4,//�������������
		};

		m_pRectDLE = new EngineNS::RectangleDataLoadEngine();
		m_pRectDLE->SetVertexData(positionArray, 6 * 8 * sizeof(float));
		m_pRectDLE->SetIndexData(indices, 12);
		//��ʼ�����ݻ���
		//�˴����㻺�������ֵ�push  �붥��shader�ļ��е�layout�����
		LayoutNS::VertexBufferLayout* pVBufLayout = m_pRectDLE->GetDataLoadEnginePointer()->GetVBufLayoutPointer();
		//�Ҵ����Ⱥ�˳���ϵ
		pVBufLayout->Push<float>(2);//ÿ2��������������������
		pVBufLayout->Push<float>(4);//ÿ4�����������嶥����ɫ
		//�������㻺�����Ͷ��㲼�ֶ���Ĺ�ϵ
		m_pRectDLE->GetDataLoadEnginePointer()->BindVBuffAndVLayout();

	}
	TestBatchRenderRect2::~TestBatchRenderRect2()
	{
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
	void TestBatchRenderRect2::onUpdate(float deltatime)
	{
	}
	void TestBatchRenderRect2::onRender()
	{

		m_pRenderE->Clear();//�������

		//ͨ������ָ�룬��ȡ������
		m_pRenderE->RendererDraw(m_pRectDLE->GetDataLoadEnginePointer(), m_pShaderMng);

	}
	void TestBatchRenderRect2::onImGUIRender()
	{
	}
}