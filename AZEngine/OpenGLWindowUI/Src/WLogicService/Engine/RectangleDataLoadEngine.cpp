#include "RectangleDataLoadEngine.h"
#include "DataLoadEnginePrivate.h"
#include "Layout/VertexBufferLayout.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"//错误检查

namespace WindowsNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	RectangleDataLoadEngine::RectangleDataLoadEngine()
	{
		m_pDLEPrivate = new DataLoadEnginePrivate();
	}

	/// <summary>
	/// 析构函数
	/// </summary>
	RectangleDataLoadEngine::~RectangleDataLoadEngine()
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
	void RectangleDataLoadEngine::SetIndexData(const unsigned int* pArray, unsigned int count)
	{
		m_pDLEPrivate->SetIndexData(pArray, count);
	}

	/// <summary>
	/// 设置顶点缓冲功能区
	/// </summary>
	/// <param name="pArray"></param>
	/// <param name="size"></param>
	void RectangleDataLoadEngine::SetVertexData(const void* pArray, unsigned int size)
	{
		m_pDLEPrivate->SetVertexData(pArray, size);
	}


	DataLoadEnginePrivate* RectangleDataLoadEngine::GetDataLoadEnginePointer() const
	{
		return m_pDLEPrivate;
	}
}
