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
		//初始化着色器并绑定
		m_pShaderMng->initShader("/Resource/Shaders/BatchL/Vertex.shader", "/Resource/Shaders/BatchL/Fragment.shader");
		m_pShaderMng->Bind();

		//顶点数据
		float positionArray[] = {
			//两个数为一个顶点，0.5f 表示在0~1的范围内占据一半
			//0.0f 0.0f 纹理坐标表示左下角，1.0f,1.0f 表示右上角
			//从0.1f 开始描述的是顶点的RGBA值 
			//前两个folat值描述顶点位置,后四个值描述顶点颜色
			-0.75f,-0.5f,0.1f,0.6f,0.96f,1.0f,
			-0.25f,-0.5f,0.1f,0.6f,0.96f,1.0f,
			-0.25f,0.5f,0.1f,0.6f,0.96f,1.0f,
			-0.75f,0.5f,0.1f,0.6f,0.96f,1.0f,
			//新增顶点 将需要产生变化的图形通过运算转化指定的顶点数据
			//通过对顶点数据的解析形成变化的效果
			0.25f,-0.5f,0.1f,0.93f,0.24f,1.0f,
			0.75f,-0.5f,0.1f,0.93f,0.24f,1.0f,
			0.75f,0.5f,0.1f,0.93f,0.24f,1.0f,
			0.25f,0.5f,0.1f,0.93f,0.24f,1.0f,
		};

		//索引缓冲区
		unsigned int indices[] = {
			0,1,2,
			2,3,0,

			4,5,6,//新增索引
			6,7,4,//描述顶点的索引
		};

		m_pRectDLE = new EngineNS::RectangleDataLoadEngine();
		m_pRectDLE->SetVertexData(positionArray, 6 * 8 * sizeof(float));
		m_pRectDLE->SetIndexData(indices, 12);
		//初始化数据环境
		//此处顶点缓冲区布局的push  与顶点shader文件中的layout相关联
		LayoutNS::VertexBufferLayout* pVBufLayout = m_pRectDLE->GetDataLoadEnginePointer()->GetVBufLayoutPointer();
		//且存在先后顺序关系
		pVBufLayout->Push<float>(2);//每2个浮点数描述顶点坐标
		pVBufLayout->Push<float>(4);//每4个浮点数鸟叔顶点颜色
		//建立顶点缓冲区和顶点布局定义的关系
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

		m_pRenderE->Clear();//清楚背景

		//通过常量指针，换取常引用
		m_pRenderE->RendererDraw(m_pRectDLE->GetDataLoadEnginePointer(), m_pShaderMng);

	}
	void TestBatchRenderRect2::onImGUIRender()
	{
	}
}