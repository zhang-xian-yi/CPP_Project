#include "DataLoadEnginePrivate.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexBuffer.h"
#include "Layout/VertexBufferLayout.h"
#include "DataSrc/VertexArray.h"
#include "Error/ErrorMacroDefie.h"//������
/// <summary>
/// ���캯��
/// </summary>
EngineNS::DataLoadEnginePrivate::DataLoadEnginePrivate()
{
	m_pIndexBufferS = new BuffersNS::IndexBuffer();
	m_pVertexBufferS = new BuffersNS::VertexBuffer();
	m_pVArray = new DataSrcNS::VertexArray();
	m_pVBufLayout = new LayoutNS::VertexBufferLayout();
}

/// <summary>
/// ��������
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
/// �����������幦����
/// </summary>
/// <param name="pArray"></param>
/// <param name="count"></param>
void EngineNS::DataLoadEnginePrivate::SetIndexData(const unsigned int* pArray, unsigned int count)
{
	m_pIndexBufferS->SetIndexData(pArray, count);
}


/// <summary>
/// ���ö��㻺�幦����
/// </summary>
/// <param name="pArray"></param>
/// <param name="size"></param>
void EngineNS::DataLoadEnginePrivate::SetVertexData(const void* pArray, unsigned int size)
{
	m_pVertexBufferS->SetVertexData(pArray, size);
}

/// <summary>
/// ���ض��㻺�������ֵ�ָ�붨��
/// </summary>
/// <returns></returns>
LayoutNS::VertexBufferLayout* EngineNS::DataLoadEnginePrivate::GetVBufLayoutPointer() const
{
	return this->m_pVBufLayout;
}
//��ȡ���������ָ��
const DataSrcNS::VertexArray* EngineNS::DataLoadEnginePrivate::GetVertexArrayPointer() const
{
	return m_pVArray;
}
//��ȡ������������ָ��
const BuffersNS::IndexBuffer* EngineNS::DataLoadEnginePrivate::GetIndexBufferPointer() const
{
	return m_pIndexBufferS;
}

void EngineNS::DataLoadEnginePrivate::BindVBuffAndVLayout()
{
	//�������㻺�����Ͷ��㲼�ֵĹ�ϵ
	m_pVArray->BindVBuffAndVLayout(*m_pVertexBufferS, *m_pVBufLayout);
}

/// <summary>
/// �ֶ������Դ
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
