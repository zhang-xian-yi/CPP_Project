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
        //初始化环境
        m_pTextureDLE = new EngineNS::TextureDataLoadEngine();
        m_pShaderMng = new ShaderNS::ShaderManager();
        m_pRenderE = new RenderNS::RendererEngine();
        m_pTextureS = new RenderNS::TextureService();

        m_pShaderMng->initShader("/Resource/Shaders/TextureL/TVertex.shader", "/Resource/Shaders/TextureL/TFragment.shader");
        m_pShaderMng->Bind();//必须先使用gluserprogram 才可以绑定uniform变量否则该变量不会存在

        //加载纹理
        m_pTextureS->LoadFileTexture("Resource/TexturesRes/flower.jpeg");
        m_pTextureS->Bind(0);//默认为0
        m_pShaderMng->SetUniform1f("u_Texture", 0);

        //顶点数据
        float positionArray[] = {
            -100.0f,-100.0f,0.0f,0.0f,//前两个数为顶点，后两个数为纹理坐标
            100.0f,-100.0f,1.0f,0.0f,//0.0f 0.0f 纹理坐标表示左下角，1.0f,1.0f 表示右上角
            100.0f,100.0f,1.0f,1.0f,
            -100.0f,100.0f,0.0f,1.0f
        };

        //索引缓冲区
        unsigned int indices[] = {
            0,1,2,
            2,3,0,
        };

        m_pTextureDLE->SetVertexData(positionArray, 4 * 4 * sizeof(float));
        m_pTextureDLE->SetIndexData(indices, 6);
        //初始化纹理环境
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

	//动画
	void TestTexture2D::onUpdate(float deltatime)
	{
	}


    //建立一个投影矩阵,ortho产生一个正交矩阵
    //从左右上下来看分别时-2，2-1.5，1.5  描述从左到右时 -2 + 2 四个单位宽度
    //从上到下时 1.5+1.5 3各单位的高度的区域
    //Sttic 描述这个变量只能在这个文件作用域内使用
    static glm::mat4 projectMatrix = glm::ortho(0.0f, 720.0f, 0.0f, 480.0f, -1.0f, 1.0f);
    //模拟视图矩阵：相机左移 意味者对象右移
    static glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	//渲染元素
	void TestTexture2D::onRender()
	{
        /* Loop until the user closes the window */
        m_pRenderE->Clear();
        {
            //模型矩阵，xyz 三轴，x轴正向200，Y轴正向100单位，Z轴上不同
            glm::mat4 model = glm::translate(glm::mat4(1.0f), m_ModelAVec3);
            m_pShaderMng->Bind();
            m_pShaderMng->SetUniformMatrix4f("u_MVP", projectMatrix * viewMatrix * model);
            m_pRenderE->RendererDraw(m_pTextureDLE->GetDataLoadEnginePointer(), m_pShaderMng);//绘制
        }

        {
            //模型矩阵，xyz 三轴，x轴正向200，Y轴正向100单位，Z轴上不同
            glm::mat4 model = glm::translate(glm::mat4(1.0f), m_ModelBVec3);
            m_pShaderMng->Bind();
            m_pShaderMng->SetUniformMatrix4f("u_MVP", projectMatrix * viewMatrix * model);
            m_pRenderE->RendererDraw(m_pTextureDLE->GetDataLoadEnginePointer(), m_pShaderMng);//绘制
        }

	}

	//IMgui 控制响应
	void TestTexture2D::onImGUIRender()
	{
        //将模型矩阵的x坐标 与滑动Slider 绑定起来 注意这里的3
        //描述三个滑动条分别控制XYZ三个值
        ImGui::SliderFloat3("ModelA", &(m_ModelAVec3.x), 0.0f, 720.0f);
        ImGui::Text("--------------------------------------------------------");
        ImGui::SliderFloat3("ModelB", &(m_ModelBVec3.x), 0.0f, 720.0f);
	}
}