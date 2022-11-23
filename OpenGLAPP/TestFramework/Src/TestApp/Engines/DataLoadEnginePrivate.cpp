#include "DataLoadEnginePrivate.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexBuffer.h"
#include "Layout/VertexBufferLayout.h"
#include "DataSrc/VertexArray.h"
#include "Error/ErrorMacroDefie.h"//错误检查
/// <summary>
/// 构造函数
/// </summary>
EngineNS::DataLoadEnginePrivate::DataLoadEnginePrivate()
{
	m_pIndexBufferS = new BuffersNS::IndexBuffer();
	m_pVertexBufferS = new BuffersNS::VertexBuffer();
	m_pVArray = new DataSrcNS::VertexArray();
	m_pVBufLayout = new LayoutNS::VertexBufferLayout();
}

/// <summary>
/// 析构函数
/// </summary>
EngineNS::DataLoadEnginePrivate::~DataLoadEnginePrivate()
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
void EngineNS::DataLoadEnginePrivate::SetIndexData(const unsigned int* pArray, unsigned int count)
{
	m_pIndexBufferS->SetIndexData(pArray, count);
}


/// <summary>
/// 设置顶点缓冲功能区
/// </summary>
/// <param name="pArray"></param>
/// <param name="size"></param>
void EngineNS::DataLoadEnginePrivate::SetVertexData(const void* pArray, unsigned int size)
{
	m_pVertexBufferS->SetVertexData(pArray, size);
}

/// <summary>
/// 返回顶点缓冲区布局的指针定义
/// </summary>
/// <returns></returns>
LayoutNS::VertexBufferLayout* EngineNS::DataLoadEnginePrivate::GetVBufLayoutPointer() const
{
	return this->m_pVBufLayout;
}
//获取顶点数组的指针
const DataSrcNS::VertexArray* EngineNS::DataLoadEnginePrivate::GetVertexArrayPointer() const
{
	return m_pVArray;
}
//获取索引缓冲区的指针
const BuffersNS::IndexBuffer* EngineNS::DataLoadEnginePrivate::GetIndexBufferPointer() const
{
	return m_pIndexBufferS;
}

void EngineNS::DataLoadEnginePrivate::BindVBuffAndVLayout()
{
	//建立顶点缓冲区和顶点布局的关系
	m_pVArray->BindVBuffAndVLayout(*m_pVertexBufferS, *m_pVBufLayout);
}

/// <summary>
/// 手动清楚资源
/// </summary>
void EngineNS::DataLoadEnginePrivate::ReleaseSrc()
{
	if (m_pIndexBufferS != nullptr)
	{
		m_pIndexBufferS->ReleaseBuffer();
	}
	if (m_pVertexBufferS != nullptr)
	{
		m_pVertexBufferS->ReleaseBuffer();
	}
}
