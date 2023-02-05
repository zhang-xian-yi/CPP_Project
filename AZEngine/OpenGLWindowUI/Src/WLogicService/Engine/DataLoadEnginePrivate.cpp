#include "DataLoadEnginePrivate.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexBuffer.h"
#include "Layout/VertexBufferLayout.h"
#include "DataSrc/VertexArray.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"//������

namespace WindowsNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	DataLoadEnginePrivate::DataLoadEnginePrivate()
	{
		m_pIndexBufferS = new WindowsNS::IndexBuffer();
		m_pVertexBufferS = new WindowsNS::VertexBuffer();
		m_pVArray = new WindowsNS::VertexArray();
		m_pVBufLayout = new WindowsNS::VertexBufferLayout();
	}

	/// <summary>
	/// ��������
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
	/// �����������幦����
	/// </summary>
	/// <param name="pArray"></param>
	/// <param name="count"></param>
	void DataLoadEnginePrivate::SetIndexData(const unsigned int* pArray, unsigned int count)
	{
		m_pIndexBufferS->SetIndexData(pArray, count);
	}


	/// <summary>
	/// ���ö��㻺�幦����
	/// </summary>
	/// <param name="pArray"></param>
	/// <param name="size"></param>
	void DataLoadEnginePrivate::SetVertexData(const void* pArray, unsigned int size)
	{
		m_pVertexBufferS->SetStaticVertexData(pArray, size);
	}

	/// <summary>
	/// ���ض��㻺�������ֵ�ָ�붨��
	/// </summary>
	/// <returns></returns>
	VertexBufferLayout* DataLoadEnginePrivate::GetVBufLayoutPointer() const
	{
		return this->m_pVBufLayout;
	}
	//��ȡ���������ָ��
	VertexArray* DataLoadEnginePrivate::GetVertexArrayPointer() const
	{
		return m_pVArray;
	}
	//��ȡ������������ָ��
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
		//�������㻺�����Ͷ��㲼�ֵĹ�ϵ
		m_pVArray->BindVBuffAndVLayout(*m_pVertexBufferS, *m_pVBufLayout);
	}

	/// <summary>
	/// �ֶ������Դ
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
