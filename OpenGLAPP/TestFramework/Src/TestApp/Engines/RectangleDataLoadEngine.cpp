#include "RectangleDataLoadEngine.h"
#include "DataLoadEnginePrivate.h"
#include "Layout/VertexBufferLayout.h"
#include "Error/ErrorMacroDefie.h"//������
/// <summary>
/// ���캯��
/// </summary>
EngineNS::RectangleDataLoadEngine::RectangleDataLoadEngine()
{
	m_pDLEPrivate = new EngineNS::DataLoadEnginePrivate();
}

/// <summary>
/// ��������
/// </summary>
EngineNS::RectangleDataLoadEngine::~RectangleDataLoadEngine()
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
void EngineNS::RectangleDataLoadEngine::SetIndexData(const unsigned int* pArray, unsigned int count)
{
	m_pDLEPrivate->SetIndexData(pArray, count);
}

/// <summary>
/// ���ö��㻺�幦����
/// </summary>
/// <param name="pArray"></param>
/// <param name="size"></param>
void EngineNS::RectangleDataLoadEngine::SetVertexData(const void* pArray, unsigned int size)
{
	m_pDLEPrivate->SetVertexData(pArray, size);
}


void EngineNS::RectangleDataLoadEngine::InitRectangleBKColorEnvir()
{
	//�˴����㻺�������ֵ�push  �붥��shader�ļ��е�layout�����
	LayoutNS::VertexBufferLayout* pVBufLayout = m_pDLEPrivate->GetVBufLayoutPointer();
	//�Ҵ����Ⱥ�˳���ϵ
	pVBufLayout->Push<float>(2);//ÿ����������Ϊһ���������
	//�������㻺�����Ͷ��㲼�ֶ���Ĺ�ϵ
	m_pDLEPrivate->BindVBuffAndVLayout();
}

EngineNS::DataLoadEnginePrivate* EngineNS::RectangleDataLoadEngine::GetDataLoadEnginePointer() const
{
	return m_pDLEPrivate;
}
