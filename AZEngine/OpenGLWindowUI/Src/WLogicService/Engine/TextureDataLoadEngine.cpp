#include "TextureDataLoadEngine.h"
#include "DataLoadEnginePrivate.h"
#include "Layout/VertexBufferLayout.h"
#include "WCommon/WGLMacroDef.h"//������

namespace ImguiRendererNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	TextureDataLoadEngine::TextureDataLoadEngine()
	{
		m_pDLEPrivate = new DataLoadEnginePrivate();
	}

	/// <summary>
	/// ��������
	/// </summary>
	TextureDataLoadEngine::~TextureDataLoadEngine()
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
	void TextureDataLoadEngine::SetIndexData(const unsigned int* pArray, unsigned int count)
	{
		m_pDLEPrivate->SetIndexData(pArray, count);
	}

	/// <summary>
	/// ���ö��㻺�幦����
	/// </summary>
	/// <param name="pArray"></param>
	/// <param name="size"></param>
	void TextureDataLoadEngine::SetVertexData(const void* pArray, unsigned int size)
	{
		m_pDLEPrivate->SetVertexData(pArray, size);
	}

	void TextureDataLoadEngine::InitTextureEnvir()
	{
		//�˴����㻺�������ֵ�push  �붥��shader�ļ��е�layout�����
		ImguiRendererNS::VertexBufferLayout* pVBufLayout = m_pDLEPrivate->GetVBufLayoutPointer();
		//�Ҵ����Ⱥ�˳���ϵ
		pVBufLayout->Push<float>(2);//ÿ����������Ϊһ���������
		pVBufLayout->Push<float>(2);//ÿ����������Ϊһ����������
		//�������㻺�����Ͷ��㲼�ֶ���Ĺ�ϵ
		m_pDLEPrivate->BindVBuffAndVLayout();
	}

	/// <summary>
	/// ������ϸ���ݼ��ص�����
	/// </summary>
	/// <returns></returns>
	DataLoadEnginePrivate* TextureDataLoadEngine::GetDataLoadEnginePointer() const
	{
		return m_pDLEPrivate;
	}


}