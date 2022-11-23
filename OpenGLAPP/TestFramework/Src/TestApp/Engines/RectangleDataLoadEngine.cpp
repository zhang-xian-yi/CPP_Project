#include "RectangleDataLoadEngine.h"
#include "DataLoadEnginePrivate.h"
#include "Layout/VertexBufferLayout.h"
#include "Error/ErrorMacroDefie.h"//错误检查
/// <summary>
/// 构造函数
/// </summary>
EngineNS::RectangleDataLoadEngine::RectangleDataLoadEngine()
{
	m_pDLEPrivate = new EngineNS::DataLoadEnginePrivate();
}

/// <summary>
/// 析构函数
/// </summary>
EngineNS::RectangleDataLoadEngine::~RectangleDataLoadEngine()
{
	if (nullptr != m_pDLEPrivate)
	{
		m_pDLEPrivate->ReleaseSrc();//释放资源
		delete m_pDLEPrivate;
		m_pDLEPrivate = nullptr;
	}
}

/// <summary>
/// 设置索引缓冲功能区
/// </summary>
/// <param name="pArray"></param>
/// <param name="count"></param>
void EngineNS::RectangleDataLoadEngine::SetIndexData(const unsigned int* pArray, unsigned int count)
{
	m_pDLEPrivate->SetIndexData(pArray, count);
}

/// <summary>
/// 设置顶点缓冲功能区
/// </summary>
/// <param name="pArray"></param>
/// <param name="size"></param>
void EngineNS::RectangleDataLoadEngine::SetVertexData(const void* pArray, unsigned int size)
{
	m_pDLEPrivate->SetVertexData(pArray, size);
}


void EngineNS::RectangleDataLoadEngine::InitRectangleBKColorEnvir()
{
	//此处顶点缓冲区布局的push  与顶点shader文件中的layout相关联
	LayoutNS::VertexBufferLayout* pVBufLayout = m_pDLEPrivate->GetVBufLayoutPointer();
	//且存在先后顺序关系
	pVBufLayout->Push<float>(2);//每两个浮点数为一个顶点对象
	//建立顶点缓冲区和顶点布局定义的关系
	m_pDLEPrivate->BindVBuffAndVLayout();
}

EngineNS::DataLoadEnginePrivate* EngineNS::RectangleDataLoadEngine::GetDataLoadEnginePointer() const
{
	return m_pDLEPrivate;
}
