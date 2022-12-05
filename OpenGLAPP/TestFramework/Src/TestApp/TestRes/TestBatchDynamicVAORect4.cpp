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

	/// <summary>
	/// 创建指定大小的数据区域
	/// </summary>
	/// <param name="target"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="texID"></param>
	/// <returns></returns>
	static TVertex* CreateQuadrangle(TVertex* target,float x, float y, float texID)
	{
		float Vsize = 1.0f;//顶点之间的距离

		target->position = {x,y};
		target->Color = { 0.1f,0.6f,0.96f,1.0f };
		target->TexCoord = {0.0f,0.0f};
		target->TexID = texID;
		target++;//指针自增 先后偏移 sizeof(TVertex)大小的字节数 为新对象起始地址

		target->position = { x + Vsize,y };
		target->Color = { 0.1f,0.6f,0.96f,1.0f };
		target->TexCoord = { 1.0f,0.0f };
		target->TexID = texID;
		target++;//指针自增 先后偏移 sizeof(TVertex)大小的字节数 为新对象起始地址

		target->position = { x +Vsize,y + Vsize };
		target->Color = { 0.1f,0.6f,0.96f,1.0f };
		target->TexCoord = { 1.0f,1.0f };
		target->TexID = texID;
		target++;//指针自增 先后偏移 sizeof(TVertex)大小的字节数 为新对象起始地址

		target->position = { x,y+Vsize };
		target->Color = { 0.1f,0.6f,0.96f,1.0f };
		target->TexCoord = { 0.0f,1.0f };
		target->TexID = texID;
		target++;//指针自增 先后偏移 sizeof(TVertex)大小的字节数 为新对象起始地址

		return target;
	}

}

namespace TestResNS
{
	static const size_t SMaxQuadCount = 25; // 屏幕中最大四边形个数
	static const  size_t SMaxVertexCount = SMaxQuadCount * 4;//最大顶点个数
	static const size_t SMaxIndexCount = SMaxQuadCount * 6;//最大索引个数


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
		pVBufS->SetDynamicVertexData(nullptr, sizeof(BatchDynamicVAONS::TVertex) * SMaxVertexCount);
		/*
		//索引缓冲区
		unsigned int indices[] = {
			0,1,2,2,3,0,			
			//新增索引
			4,5,6,6,7,4,//描述顶点的索引			
		};
		*/
		//
		unsigned int indices[SMaxIndexCount];
		//设置索引缓冲的数据模式
		unsigned int offset = 0;//一个四边形偏移一次
		for (unsigned int i = 0; i < SMaxIndexCount; i+=6)
		{
			indices[i] = 0 + offset;
			indices[i + 1] = 1 + offset;
			indices[i + 2] = 2 + offset;

			indices[i + 3] = 2 + offset;
			indices[i + 4] = 3 + offset;
			indices[i + 5] = 0 + offset;

			offset += 4;//每次四边形六个索引点，便递增一次
		}


		m_pRectDLE->SetIndexData(indices, SMaxIndexCount);
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


		std::array<BatchDynamicVAONS::TVertex, 100> verterxArr;//定义顶点数
		BatchDynamicVAONS::TVertex* buffer = verterxArr.data();//获取数组起始指针
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
		//创建两个可以被控制的图案
		buffer = BatchDynamicVAONS::CreateQuadrangle(buffer,m_QAPosFArr[0], m_QAPosFArr[1], 0.0f);

		buffer = BatchDynamicVAONS::CreateQuadrangle(buffer,m_QBPosFArr[0], m_QBPosFArr[1], 1.0f);

		//此方法可以改变顶点缓冲区的数据， 也可以用glmapbuffer
		glBufferSubData(GL_ARRAY_BUFFER, 0, verterxArr.size() * sizeof(BatchDynamicVAONS::TVertex), verterxArr.data());
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