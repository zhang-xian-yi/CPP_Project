#include "DataLoadEngine.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexBuffer.h"
#include "Layout/VertexBufferLayout.h"
#include "DataSrc/VertexArray.h"
/// <summary>
/// 构造函数
/// </summary>
EngineNS::DataLoadEngine::DataLoadEngine()
{
	m_pIndexBufferS = new BuffersNS::IndexBuffer();
	m_pVertexBufferS = new BuffersNS::VertexBuffer();
	m_pVArray = new DataSrcNS::VertexArray();
	m_pVBufLayout = new LayoutNS::VertexBufferLayout();
}

/// <summary>
/// 析构函数
/// </summary>
EngineNS::DataLoadEngine::~DataLoadEngine()
{
	if (nullptr != m_pIndexBufferS)
	{
		delete m_pIndexBufferS;
		m_pIndexBufferS = nullptr;
	}
	if (nullptr != m_pVertexBufferS)
	{
		delete m_pVertexBufferS;
		m_pVertexBufferS = nullptr;
	}
	if (nullptr != m_pVBufLayout)
	{
		delete m_pVBufLayout;
		m_pVBufLayout = nullptr;
	}
	if (nullptr != m_pVArray)
	{
		delete m_pVArray;
		m_pVArray = nullptr;
	}
}

/// <summary>
/// 设置索引缓冲功能区
/// </summary>
/// <param name="pArray"></param>
/// <param name="count"></param>
void EngineNS::DataLoadEngine::SetIndexData(const unsigned int* pArray, unsigned int count)
{
	m_pIndexBufferS->SetIndexData(pArray, count);
}

const BuffersNS::IndexBuffer& EngineNS::DataLoadEngine::GetIndexBuffer() const
{
	// TODO: 在此处插入 return 语句
	return *(this->m_pIndexBufferS);
}

/// <summary>
/// 设置顶点缓冲功能区
/// </summary>
/// <param name="pArray"></param>
/// <param name="size"></param>
void EngineNS::DataLoadEngine::SetVertexData(const void* pArray, unsigned int size)
{
	m_pVertexBufferS->SetVertexData(pArray, size);
}

const DataSrcNS::VertexArray& EngineNS::DataLoadEngine::GetVArray() const
{
	// TODO: 在此处插入 return 语句
	return *(this->m_pVArray);
}


void EngineNS::DataLoadEngine::InitDataEnvir()
{
	m_pVBufLayout->Push<float>(2);//每两个浮点数为一个顶点对象
	m_pVBufLayout->Push<float>(2);//每两个浮点数为一个纹理坐标
	//绑定缓冲区和布局定义
	m_pVArray->BindVBuffAndVLayout(*m_pVertexBufferS, *m_pVBufLayout);
}

/// <summary>
/// 手动清楚资源
/// </summary>
void EngineNS::DataLoadEngine::ReleaseSrc()
{
	m_pVertexBufferS->ReleaseBuffer();
	m_pIndexBufferS->ReleaseBuffer();
}
