#include "DefSysResponse.h"
#include <memory>

namespace MdlCommonNS
{
    DefSysResponse::DefSysResponse()
        :m_pData(nullptr)
    {

    }
    DefSysResponse::DefSysResponse(std::any& data)
        :m_pData(&data)
    {
    }

    DefSysResponse::~DefSysResponse()
    {
        if (m_pData && m_pData->has_value())
        {
            //delete m_pData;
            m_pData = nullptr;//��ֹ����ͷ�
        }
    }
    /// <summary>
    /// ��������
    /// </summary>
    /// <param name="data"></param>
    void DefSysResponse::SetData(std::any& data)
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
    std::any& DefSysResponse::GetData() const
    {
        // TODO: �ڴ˴����� return ���
        return *m_pData;
    }

}
