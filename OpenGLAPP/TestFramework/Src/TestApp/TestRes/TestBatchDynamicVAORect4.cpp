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

	//定义顶点
	struct TVertex
	{
		VecF2 position;//位置
		VecF4 Color;//纹理
		VecF2 TexCoord;//纹理坐标
		float TexID;//纹理槽号
	};

	static std::array<TVertex, 4> CreateQuadrangle(float x, float y, float texID)
	{
		size_t Vsize = 1.0f;//顶点之间的距离

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
		//初始化着色器并绑定
		m_pShaderMng->initShader("/Resource/Shaders/BatchL/BatchVS3.shader", "/Resource/Shaders/BatchL/BatchFS3.shader");
		m_pShaderMng->Bind();
		int iArr[2] = { 0,1 };
		m_pShaderMng->SetUniform1iv("u_Textures", iArr, 2);

		//保存以及加载纹理
		m_pTextureS = new RenderNS::TextureService();
		m_ATexSolt = m_pTextureS->LoadFileTexture("Resource/TexturesRes/flower.jpeg");
		m_BTexSolt = m_pTextureS->LoadFileTexture("Resource/TexturesRes/sky.jpeg");

		m_pRectDLE = new EngineNS::RectangleDataLoadEngine();
		auto pDataLoadE = m_pRectDLE->GetDataLoadEnginePointer();
		auto pVBufS = pDataLoadE->GetVertexBufferPointer();
		//建立一个100 个顶点的缓冲区
		pVBufS->SetDynamicVertexData(nullptr, sizeof(BatchDynamicVAONS::TVertex) * 100);
		//索引缓冲区
		unsigned int indices[] = {
			0,1,2,
			2,3,0,

			4,5,6,//新增索引
			6,7,4,//描述顶点的索引
		};

		m_pRectDLE->SetIndexData(indices, 12);
		//初始化数据环境
		//此处顶点缓冲区布局的push  与顶点shader文件中的layout相关联
		LayoutNS::VertexBufferLayout* pVBufLayout = m_pRectDLE->GetDataLoadEnginePointer()->GetVBufLayoutPointer();
		//且存在先后顺序关系
		pVBufLayout->Push<float>(2);//2个浮点数描述顶点坐标
		pVBufLayout->Push<float>(4);//4个浮点数描述顶点颜色
		pVBufLayout->Push<float>(2);//2个浮点数描述纹理坐标
		pVBufLayout->Push<float>(1);//1个浮点数描述纹理槽号索引
		//建立顶点缓冲区和顶点布局定义的关系
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
		//设置每次更新是纹理槽号所绑定的纹理渲染ID
		glBindTextureUnit(0, m_ATexSolt);//花
		glBindTextureUnit(1, m_BTexSolt);//星空

		auto q0 = BatchDynamicVAONS::CreateQuadrangle(m_QAPosFArr[0], m_QAPosFArr[1], 0.0f);
		auto q1 = BatchDynamicVAONS::CreateQuadrangle(m_QBPosFArr[0], m_QBPosFArr[1], 1.0f);
		//定义八个顶点的数组
		BatchDynamicVAONS::TVertex TVertexs[8];

		memcpy(TVertexs, q0.data(), q0.size() * sizeof(BatchDynamicVAONS::TVertex));
		memcpy(TVertexs + q0.size(), q1.data(), q1.size() * sizeof(BatchDynamicVAONS::TVertex));
		//此方法可以改变顶点缓冲区的数据， 也可以用glmapbuffer
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(TVertexs), TVertexs);
	
	}
	void TestBatchDynamicVAORect4::onRender()
	{

		m_pRenderE->Clear();//清楚背景

		//通过常量指针，换取常引用
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