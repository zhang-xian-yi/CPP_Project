#include "TestTexture2D.h"
#include "imGui/imgui.h"
#include "imGui/imgui_impl_glfw.h"
#include "imGui/imgui_impl_opengl3.h"

namespace TestResNS
{
	TestTexture2D::TestTexture2D()
        :m_ModelAVec3(glm::vec3(0.0f, 0.0f, 0.0f)),
         m_ModelBVec3(glm::vec3(100.0f, 100.0f, 0.0f))
	{
        //��ʼ������
        m_pTextureDLE = new EngineNS::TextureDataLoadEngine();
        m_pShaderMng = new ShaderNS::ShaderManager();
        m_pRenderE = new RenderNS::RendererEngine();
        m_pTextureS = new RenderNS::TextureService();

        m_pShaderMng->initShader("/Resource/Shaders/TextureL/TVertex.shader", "/Resource/Shaders/TextureL/TFragment.shader");
        m_pShaderMng->Bind();//������ʹ��gluserprogram �ſ��԰�uniform��������ñ����������

        //��������
        m_pTextureS->LoadFileTexture("Resource/TexturesRes/flower.jpeg");
        m_pTextureS->Bind(0);//Ĭ��Ϊ0
        m_pShaderMng->SetUniform1f("u_Texture", 0);

        //��������
        float positionArray[] = {
            -100.0f,-100.0f,0.0f,0.0f,//ǰ������Ϊ���㣬��������Ϊ��������
            100.0f,-100.0f,1.0f,0.0f,//0.0f 0.0f ���������ʾ���½ǣ�1.0f,1.0f ��ʾ���Ͻ�
            100.0f,100.0f,1.0f,1.0f,
            -100.0f,100.0f,0.0f,1.0f
        };

        //����������
        unsigned int indices[] = {
            0,1,2,
            2,3,0,
        };

        m_pTextureDLE->SetVertexData(positionArray, 4 * 4 * sizeof(float));
        m_pTextureDLE->SetIndexData(indices, 6);
        //��ʼ��������
        m_pTextureDLE->InitTextureEnvir();

	}
	TestTexture2D::~TestTexture2D()
	{
        if (m_pTextureDLE != nullptr)
        {
            delete m_pTextureDLE;
            m_pTextureDLE = nullptr;
        }
        if (m_pShaderMng != nullptr)
        {
            delete m_pShaderMng;
            m_pShaderMng = nullptr;
        }
        if (m_pRenderE != nullptr)
        {
            delete m_pRenderE;
            m_pRenderE = nullptr;
        }
        if (m_pTextureS != nullptr)
        {
            delete m_pTextureS;
            m_pTextureS = nullptr;
        }

	}

	//����
	void TestTexture2D::onUpdate(float deltatime)
	{
	}


    //����һ��ͶӰ����,ortho����һ����������
    //���������������ֱ�ʱ-2��2-1.5��1.5  ����������ʱ -2 + 2 �ĸ���λ���
    //���ϵ���ʱ 1.5+1.5 3����λ�ĸ߶ȵ�����
    //Sttic �����������ֻ��������ļ���������ʹ��
    static glm::mat4 projectMatrix = glm::ortho(0.0f, 720.0f, 0.0f, 480.0f, -1.0f, 1.0f);
    //ģ����ͼ����������� ��ζ�߶�������
    static glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	//��ȾԪ��
	void TestTexture2D::onRender()
	{
        /* Loop until the user closes the window */
        m_pRenderE->Clear();
        {
            //ģ�;���xyz ���ᣬx������200��Y������100��λ��Z���ϲ�ͬ
            glm::mat4 model = glm::translate(glm::mat4(1.0f), m_ModelAVec3);
            m_pShaderMng->Bind();
            m_pShaderMng->SetUniformMatrix4f("u_MVP", projectMatrix * viewMatrix * model);
            m_pRenderE->RendererDraw(m_pTextureDLE->GetDataLoadEnginePointer(), m_pShaderMng);//����
        }

        {
            //ģ�;���xyz ���ᣬx������200��Y������100��λ��Z���ϲ�ͬ
            glm::mat4 model = glm::translate(glm::mat4(1.0f), m_ModelBVec3);
            m_pShaderMng->Bind();
            m_pShaderMng->SetUniformMatrix4f("u_MVP", projectMatrix * viewMatrix * model);
            m_pRenderE->RendererDraw(m_pTextureDLE->GetDataLoadEnginePointer(), m_pShaderMng);//����
        }

	}

	//IMgui ������Ӧ
	void TestTexture2D::onImGUIRender()
	{
        //��ģ�;����x���� �뻬��Slider ������ ע�������3
        //���������������ֱ����XYZ����ֵ
        ImGui::SliderFloat3("ModelA", &(m_ModelAVec3.x), 0.0f, 720.0f);
        ImGui::Text("--------------------------------------------------------");
        ImGui::SliderFloat3("ModelB", &(m_ModelBVec3.x), 0.0f, 720.0f);
	}
}