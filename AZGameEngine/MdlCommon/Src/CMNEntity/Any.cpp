#include "Any.h"

namespace MdlCommonNS
{
    /*any ���ģ�嶨�庯��   ******************************************************************************************/

    /// <summary>
    /// �������캯��
    /// </summary>
    /// <param name="any"></param>
    Any::Any(const Any& any) 
        : m_pValue(any.GetHolderPointer()->clone())
    { }

    Any::~Any()
    {
        if (m_pValue)
        {
            delete m_pValue;
        }
    }

    /// <summary>
    /// ��ȡֵ����ָ��
    /// </summary>
    /// <returns></returns>
    BaseHolder* Any::GetHolderPointer() const
    {
        return m_pValue;
    }
    /// <summary>
    /// s����ֵ����ָ��
    /// </summary>
    /// <param name="pointer"></param>
    void Any::SetHolderPointer(BaseHolder* pointer)
    {
        m_pValue = pointer;
    }
}