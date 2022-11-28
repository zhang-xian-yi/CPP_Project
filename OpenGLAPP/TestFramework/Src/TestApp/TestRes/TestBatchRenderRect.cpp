#include "TestBatchRenderRect.h"
#include "Error/ErrorMacroDefie.h"
#include "imGui/imgui.h"
#include "Engines/DataLoadEnginePrivate.h"

namespace TestResNS
{
	TestBatchRenderRect::TestBatchRenderRect()
	{

		m_pRenderE = new RenderNS::RendererEngine();
		m_pShaderMng = new ShaderNS::ShaderManager();
		//��ʼ����ɫ������
		m_pShaderMng->initShader("/Resource/Shaders/Vertex.shader", "/Resource/Shaders/Fragment.shader");
		m_pShaderMng->Bind();

		//��������
		float positionArray[] = {
			-0.75f,-0.5f,//������Ϊһ�����㣬0.5f ��ʾ��0~1�ķ�Χ��ռ��һ��
			-0.25f,-0.5f,//0.0f 0.0f ���������ʾ���½ǣ�1.0f,1.0f ��ʾ���Ͻ�
			-0.25f,0.5f,
			-0.75f,0.5f,

			 0.25f,-0.5f, //�������� ����Ҫ�����仯��ͼ��ͨ������ת��ָ���Ķ�������
			 0.75f,-0.5f,//ͨ���Զ������ݵĽ����γɱ仯��Ч��
			 0.75f,0.5f,
			 0.25f,0.5f
		};

		//����������
		unsigned int indices[] = {
			0,1,2,
			2,3,0,

			4,5,6,//��������
			6,7,4,//�������������
		};

		m_pRectDLE = new EngineNS::RectangleDataLoadEngine();
		m_pRectDLE->SetVertexData(positionArray, 2 * 8 * sizeof(float));
		m_pRectDLE->SetIndexData(indices, 12);
		//��ʼ�����ݻ���
		m_pRectDLE->InitRectangleBKColorEnvir();

	}
	TestBatchRenderRect::~TestBatchRenderRect()
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
	void TestBatchRenderRect::onUpdate(float deltatime)
	{
	}
	void TestBatchRenderRect::onRender()
	{
		//��Ⱦ��ɫ
		static float currRedValue = 0.2f;//��ǰ����ɫ
		static float redStep = 0.05f;//ÿ�κ�ɫ�Ĳ���

		m_pRenderE->Clear();//�������

		//ͨ������ˢ��Red ֵ��ʹ�������θı���ɫ
		//������ɫ��ͳһ���� ʹ�������ñ���������ɫ����ʹ��
		m_pShaderMng->SetUniform4f("u_Color", currRedValue, 0.3f, 0.8f, 1.0f);
		//��Ⱦ����

		//ͨ������ָ�룬��ȡ������
		m_pRenderE->RendererDraw(m_pRectDLE->GetDataLoadEnginePointer(), m_pShaderMng);
		//�����߽��ʱ�򲽳�ȡ����ʹ����ɫ��0��1����˳��䶯
		if (currRedValue > 1.0f || currRedValue < 0.0f)
		{
			redStep = -redStep;
		}
		currRedValue += redStep;

	}
	void TestBatchRenderRect::onImGUIRender()
	{
	}
}