#include "TestBatchRenderRect.h"
#include "Error/ErrorMacroDefie.h"
#include "imGui/imgui.h"
#include "Engines/DataLoadEnginePrivate.h"
#include "Engines/Layout/VertexBufferLayout.h"
namespace TestResNS
{
	TestBatchRenderRect::TestBatchRenderRect()
	{

		m_pRenderE = new RenderNS::RendererEngine();
		m_pShaderMng = new ShaderNS::ShaderManager();
		//初始化着色器并绑定
		m_pShaderMng->initShader("/Resource/Shaders/DefaultL//Vertex.shader", "/Resource/Shaders/DefaultL/Fragment.shader");
		m_pShaderMng->Bind();

		//顶点数据
		float positionArray[] = {
			//两个数为一个顶点，0.5f 表示在0~1的范围内占据一半
			//0.0f 0.0f 纹理坐标表示左下角，1.0f,1.0f 表示右上角
			//从0.1f 开始描述的是顶点的RGBA值 
			//前两个folat值描述顶点位置,后四个值描述顶点颜色
			-0.75f,-0.5f,
			-0.25f,-0.5f,
			-0.25f,0.5f,
			-0.75f,0.5f,
			 //新增顶点 将需要产生变化的图形通过运算转化指定的顶点数据
			 //通过对顶点数据的解析形成变化的效果
			 0.25f,-0.5f,
			 0.75f,-0.5f,
			 0.75f,0.5f,
			 0.25f,0.5f,
		};

		//索引缓冲区
		unsigned int indices[] = {
			0,1,2,
			2,3,0,

			4,5,6,//新增索引
			6,7,4,//描述顶点的索引
		};

		m_pRectDLE = new EngineNS::RectangleDataLoadEngine();
		m_pRectDLE->SetVertexData(positionArray, 2 * 8 * sizeof(float));
		m_pRectDLE->SetIndexData(indices, 12);
		//初始化数据环境
		//此处顶点缓冲区布局的push  与顶点shader文件中的layout相关联
		LayoutNS::VertexBufferLayout* pVBufLayout = m_pRectDLE->GetDataLoadEnginePointer()->GetVBufLayoutPointer();
		//且存在先后顺序关系
		pVBufLayout->Push<float>(2);//每2个浮点数描述顶点坐标
		//建立顶点缓冲区和顶点布局定义的关系
		m_pRectDLE->GetDataLoadEnginePointer()->BindVBuffAndVLayout();

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
		//渲染颜色
		static float currRedValue = 0.2f;//当前的颜色
		static float redStep = 0.05f;//每次红色的步长

		m_pRenderE->Clear();//清楚背景

		//通过反复刷新Red 值来使得正方形改变颜色
		//设置着色器统一变量 使用纹理后该变量不在着色器中使用
		m_pShaderMng->SetUniform4f("u_Color", currRedValue, 0.3f, 0.8f, 1.0f);
		//渲染对象

		//通过常量指针，换取常引用
		m_pRenderE->RendererDraw(m_pRectDLE->GetDataLoadEnginePointer(), m_pShaderMng);
		//超出边界的时候步长取反，使得颜色从0到1来回顺序变动
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