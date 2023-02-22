#include "MatrixDataLoadEngine.h"
#include "DataLoadEnginePrivate.h"
#include "Layout/VertexBufferLayout.h"
#include "WCommon/WGLMacroDef.h"//错误检查

namespace ImguiRendererNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	MatrixDataLoadEngine::MatrixDataLoadEngine()
	{
		m_pDLEPrivate = new DataLoadEnginePrivate();
	}

	/// <summary>
	/// 析构函数
	/// </summary>
	MatrixDataLoadEngine::~MatrixDataLoadEngine()
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
	void MatrixDataLoadEngine::SetIndexData(const unsigned int* pArray, unsigned int count)
	{
		m_pDLEPrivate->SetIndexData(pArray, count);
	}

	/// <summary>
	/// 设置顶点缓冲功能区
	/// </summary>
	/// <param name="pArray"></param>
	/// <param name="size"></param>
	void MatrixDataLoadEngine::SetVertexData(const void* pArray, unsigned int size)
	{
		m_pDLEPrivate->SetVertexData(pArray, size);
	}


	DataLoadEnginePrivate* MatrixDataLoadEngine::GetDataLoadEnginePointer() const
	{
		return m_pDLEPrivate;
	}
}
