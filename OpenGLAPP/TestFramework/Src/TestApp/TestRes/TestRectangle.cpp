#include "TestRectangle.h"
#include "Error/ErrorMacroDefie.h"
#include "imGui/imgui.h"

namespace TestResNS
{
	TestRectangle::TestRectangle()
	{
		m_pRenderE = new RenderNS::RendererEngine();
		m_pShaderMng = new ShaderNS::ShaderManager();
		//��ʼ����ɫ������
		m_pShaderMng->initShader("/Resource/Shaders/Vertex.shader", "/Resource/Shaders/Fragment.shader");
		m_pShaderMng->Bind();

		//��������
		float positionArray[] = {
			-100.0f,-100.0f,//ǰ������Ϊ���㣬��������Ϊ��������
			100.0f,-100.0f,//0.0f 0.0f ���������ʾ���½ǣ�1.0f,1.0f ��ʾ���Ͻ�
			100.0f,100.0f,
			-100.0f,100.0f
		};

		//����������
		unsigned int indices[] = {
			0,1,2,
			2,3,0,
		};

		m_pRectDLE = new EngineNS::RectangleDataLoadEngine();
		m_pRectDLE->SetVertexData(positionArray, 2 * 4 * sizeof(float));
		m_pRectDLE->SetIndexData(indices, 6);
		//��ʼ�����ݻ���
		m_pRectDLE->InitRectangleBKColorEnvir();
	}
	TestRectangle::~TestRectangle()
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


	void TestRectangle::onUpdate(float deltatime)
	{
	}
	
	void TestRectangle::onRender()
	{
		//��Ⱦ��ɫ
		static float currRedValue = 0.2f;//��ǰ����ɫ
		static float redStep = 0.05f;//ÿ�κ�ɫ�Ĳ���

		m_pRenderE->Clear();//�������

		//ͨ������ˢ��Red ֵ��ʹ�������θı���ɫ
		//������ɫ��ͳһ���� ʹ�������ñ���������ɫ����ʹ��
		m_pShaderMng->SetUniform4f("u_Color", currRedValue, 0.3f, 0.8f, 1.0f);
		//��Ⱦ����
		m_pRenderE->RendererDraw(m_pRectDLE->GetDataLoadEnginePointer(), m_pShaderMng);
		//�����߽��ʱ�򲽳�ȡ����ʹ����ɫ��0��1����˳��䶯
		if (currRedValue > 1.0f || currRedValue < 0.0f)
		{
			redStep = -redStep;
		}
		currRedValue += redStep;
	}
	
	//��ȾIMGUI
	void TestRectangle::onImGUIRender()
	{

	}
}
