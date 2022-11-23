#include "TextureDataLoadEngine.h"
#include "DataLoadEnginePrivate.h"
#include "Layout/VertexBufferLayout.h"
#include "Error/ErrorMacroDefie.h"//错误检查
/// <summary>
/// 构造函数
/// </summary>
EngineNS::TextureDataLoadEngine::TextureDataLoadEngine()
{
	m_pDLEPrivate = new EngineNS::DataLoadEnginePrivate();
}

/// <summary>
/// 析构函数
/// </summary>
EngineNS::TextureDataLoadEngine::~TextureDataLoadEngine()
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
void EngineNS::TextureDataLoadEngine::SetIndexData(const unsigned int* pArray, unsigned int count)
{
	m_pDLEPrivate->SetIndexData(pArray, count);
}

/// <summary>
/// 设置顶点缓冲功能区
/// </summary>
/// <param name="pArray"></param>
/// <param name="size"></param>
void EngineNS::TextureDataLoadEngine::SetVertexData(const void* pArray, unsigned int size)
{
	m_pDLEPrivate->SetVertexData(pArray, size);
}



void EngineNS::TextureDataLoadEngine::InitTextureEnvir()
{
	//此处顶点缓冲区布局的push  与顶点shader文件中的layout相关联
	LayoutNS::VertexBufferLayout* pVBufLayout = m_pDLEPrivate->GetVBufLayoutPointer();
	//且存在先后顺序关系
	pVBufLayout->Push<float>(2);//每两个浮点数为一个顶点对象
	pVBufLayout->Push<float>(2);//每两个浮点数为一个纹理坐标
	//建立顶点缓冲区和顶点布局定义的关系
	m_pDLEPrivate->BindVBuffAndVLayout();
}

/// <summary>
/// 返回详细数据加载的引用
/// </summary>
/// <returns></returns>
EngineNS::DataLoadEnginePrivate* EngineNS::TextureDataLoadEngine::GetDataLoadEnginePointer() const
{
	return m_pDLEPrivate;
}

