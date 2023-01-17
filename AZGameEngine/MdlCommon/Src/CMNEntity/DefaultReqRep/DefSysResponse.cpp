#include "DefSysResponse.h"
#include <memory>

namespace MdlCommonNS
{
    DefSysResponse::DefSysResponse()
        :m_pData(nullptr)
    {

    }
    DefSysResponse::~DefSysResponse()
    {
        if (m_pData)
        {
            delete m_pData;
            m_pData = nullptr;
        }
    }
    /// <summary>
    /// ��������
    /// </summary>
    /// <param name="data"></param>
    void DefSysResponse::SetData(Any& data)
    {
        //��ֵ,���ڿ���data�������ݣ��������ܴ��ڲ���Ӱ��
        //*m_pData = data;
        //ȡ��ַ��ֱ�ӿ��ƶ����ڴ棬������������ʱ���ͷ�
        m_pData = &data;
    }

    /// <summary>
    /// ��ȡ����
    /// </summary>
    /// <returns></returns>
    Any& DefSysResponse::GetData() const
    {
        // TODO: �ڴ˴����� return ���
        return *m_pData;
    }

}
