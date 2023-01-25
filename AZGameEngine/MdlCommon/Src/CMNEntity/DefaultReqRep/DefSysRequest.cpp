#include "DefSysRequest.h"

namespace MdlCommonNS
{
	DefSysRequest::DefSysRequest()
		:m_pData(nullptr)
	{
	}

	//
	DefSysRequest::~DefSysRequest()
	{
		if (m_pData)
		{
			delete m_pData;
			m_pData = nullptr;
		}
	}
	/// <summary>
	/// ���ö�Ӧ���͵�����
	/// </summary>
	/// <param name="data"></param>
	void DefSysRequest::SetData(std::any& data)
	{
		//��ֵ,���ڿ���data�������ݣ��������ܴ��ڲ���Ӱ��
		//*m_pData = data;
		//ȡ��ַ��ֱ�ӿ��ƶ����ڴ棬������������ʱ���ͷ�
		m_pData = &data;
	}

	/// <summary>
	/// ��ȡָ��������
	/// </summary>
	/// <returns></returns>
	std::any& DefSysRequest::GetData() const
	{
		return *m_pData;
	}
}
