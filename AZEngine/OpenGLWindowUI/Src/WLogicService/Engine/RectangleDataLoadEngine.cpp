#include "RectangleDataLoadEngine.h"
#include "DataLoadEnginePrivate.h"
#include "Layout/VertexBufferLayout.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"//������

namespace WindowsNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	RectangleDataLoadEngine::RectangleDataLoadEngine()
	{
		m_pDLEPrivate = new DataLoadEnginePrivate();
	}

	/// <summary>
	/// ��������
	/// </summary>
	RectangleDataLoadEngine::~RectangleDataLoadEngine()
	{
		if (nullptr != m_pDLEPrivate)
		{
			m_pDLEPrivate->ReleaseSrc();//�ͷ���Դ
			delete m_pDLEPrivate;
			m_pDLEPrivate = nullptr;
		}
	}

	/// <summary>
	/// �����������幦����
	/// </summary>
	/// <param name="pArray"></param>
	/// <param name="count"></param>
	void RectangleDataLoadEngine::SetIndexData(const unsigned int* pArray, unsigned int count)
	{
		m_pDLEPrivate->SetIndexData(pArray, count);
	}

	/// <summary>
	/// ���ö��㻺�幦����
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
