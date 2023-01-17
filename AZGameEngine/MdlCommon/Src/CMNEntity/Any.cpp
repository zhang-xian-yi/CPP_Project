#include "Any.h"

namespace MdlCommonNS
{
    /*any 类的模板定义函数   ******************************************************************************************/

    /// <summary>
    /// 拷贝构造函数
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
    /// 获取值类型指针
    /// </summary>
    /// <returns></returns>
    BaseHolder* Any::GetHolderPointer() const
    {
        return m_pValue;
    }
    /// <summary>
    /// s设置值类型指针
    /// </summary>
    /// <param name="pointer"></param>
    void Any::SetHolderPointer(BaseHolder* pointer)
    {
        m_pValue = pointer;
    }
}