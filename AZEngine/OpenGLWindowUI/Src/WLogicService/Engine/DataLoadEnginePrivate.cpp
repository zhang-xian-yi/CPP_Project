#include "DataLoadEnginePrivate.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexBuffer.h"
#include "Layout/VertexBufferLayout.h"
#include "DataSrc/VertexArray.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"//错误检查

namespace WindowsNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	DataLoadEnginePrivate::DataLoadEnginePrivate()
	{
		m_pIndexBufferS = new WindowsNS::IndexBuffer();
		m_pVertexBufferS = new WindowsNS::VertexBuffer();
		m_pVArray = new WindowsNS::VertexArray();
		m_pVBufLayout = new WindowsNS::VertexBufferLayout();
	}

	/// <summary>
	/// 析构函数
	/// </summary>
	DataLoadEnginePrivate::~DataLoadEnginePrivate()
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
	void DataLoadEnginePrivate::SetIndexData(const unsigned int* pArray, unsigned int count)
	{
		m_pIndexBufferS->SetIndexData(pArray, count);
	}


	/// <summary>
	/// 设置顶点缓冲功能区
	/// </summary>
	/// <param name="pArray"></param>
	/// <param name="size"></param>
	void DataLoadEnginePrivate::SetVertexData(const void* pArray, unsigned int size)
	{
		m_pVertexBufferS->SetStaticVertexData(pArray, size);
	}

	/// <summary>
	/// 返回顶点缓冲区布局的指针定义
	/// </summary>
	/// <returns></returns>
	VertexBufferLayout* DataLoadEnginePrivate::GetVBufLayoutPointer() const
	{
		return this->m_pVBufLayout;
	}
	//获取顶点数组的指针
	VertexArray* DataLoadEnginePrivate::GetVertexArrayPointer() const
	{
		return m_pVArray;
	}
	//获取索引缓冲区的指针
	IndexBuffer* DataLoadEnginePrivate::GetIndexBufferPointer() const
	{
		return m_pIndexBufferS;
	}

	VertexBuffer* DataLoadEnginePrivate::GetVertexBufferPointer() const
	{
		return m_pVertexBufferS;
	}

	void DataLoadEnginePrivate::BindVBuffAndVLayout()
	{
		//建立顶点缓冲区和顶点布局的关系
		m_pVArray->BindVBuffAndVLayout(*m_pVertexBufferS, *m_pVBufLayout);
	}

	/// <summary>
	/// 手动清楚资源
	/// </summary>
	void DataLoadEnginePrivate::ReleaseSrc()
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
}
