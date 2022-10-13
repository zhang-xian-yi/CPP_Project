#include "DataLoadEngine.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexBuffer.h"
#include "Layout/VertexBufferLayout.h"
#include "DataSrc/VertexArray.h"
/// <summary>
/// ���캯��
/// </summary>
EngineNS::DataLoadEngine::DataLoadEngine()
{
	m_pIndexBufferS = new BuffersNS::IndexBuffer();
	m_pVertexBufferS = new BuffersNS::VertexBuffer();
	m_pVArray = new DataSrcNS::VertexArray();
	m_pVBufLayout = new LayoutNS::VertexBufferLayout();
}

/// <summary>
/// ��������
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
/// �����������幦����
/// </summary>
/// <param name="pArray"></param>
/// <param name="count"></param>
void EngineNS::DataLoadEngine::SetIndexData(const unsigned int* pArray, unsigned int count)
{
	m_pIndexBufferS->SetIndexData(pArray, count);
}

const BuffersNS::IndexBuffer& EngineNS::DataLoadEngine::GetIndexBuffer() const
{
	// TODO: �ڴ˴����� return ���
	return *(this->m_pIndexBufferS);
}

/// <summary>
/// ���ö��㻺�幦����
/// </summary>
/// <param name="pArray"></param>
/// <param name="size"></param>
void EngineNS::DataLoadEngine::SetVertexData(const void* pArray, unsigned int size)
{
	m_pVertexBufferS->SetVertexData(pArray, size);
}

const DataSrcNS::VertexArray& EngineNS::DataLoadEngine::GetVArray() const
{
	// TODO: �ڴ˴����� return ���
	return *(this->m_pVArray);
}


void EngineNS::DataLoadEngine::InitDataEnvir()
{
	m_pVBufLayout->Push<float>(2);//ÿ����������Ϊһ���������
	m_pVBufLayout->Push<float>(2);//ÿ����������Ϊһ����������
	//�󶨻������Ͳ��ֶ���
	m_pVArray->BindVBuffAndVLayout(*m_pVertexBufferS, *m_pVBufLayout);
}

/// <summary>
/// �ֶ������Դ
/// </summary>
void EngineNS::DataLoadEngine::ReleaseSrc()
{
	m_pVertexBufferS->ReleaseBuffer();
	m_pIndexBufferS->ReleaseBuffer();
}
