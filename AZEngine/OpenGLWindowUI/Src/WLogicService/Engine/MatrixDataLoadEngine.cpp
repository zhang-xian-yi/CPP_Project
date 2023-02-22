#include "MatrixDataLoadEngine.h"
#include "DataLoadEnginePrivate.h"
#include "Layout/VertexBufferLayout.h"
#include "WCommon/WGLMacroDef.h"//������

namespace ImguiRendererNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	MatrixDataLoadEngine::MatrixDataLoadEngine()
	{
		m_pDLEPrivate = new DataLoadEnginePrivate();
	}

	/// <summary>
	/// ��������
	/// </summary>
	MatrixDataLoadEngine::~MatrixDataLoadEngine()
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
	void MatrixDataLoadEngine::SetIndexData(const unsigned int* pArray, unsigned int count)
	{
		m_pDLEPrivate->SetIndexData(pArray, count);
	}

	/// <summary>
	/// ���ö��㻺�幦����
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
