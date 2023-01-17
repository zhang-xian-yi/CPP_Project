#include "Any.h"

namespace MdlCommonNS
{
    //����ֵ�Ľӿ�
    class BaseHolder
    {
    public:
        BaseHolder() { }
        virtual ~BaseHolder() { }
        virtual BaseHolder* clone() = 0;
    };

    //����ֵ��ʵ��ģ����
    template<typename T>
    class Holder : public BaseHolder
    {
    public:
        Holder(const T& t) : m_value(t) {}
        ~Holder() {}
    public:
        BaseHolder* clone() override
        {
            //�������¶��忽������������delete����ָ��ʱ�������ͷŴӶ�����
            return new Holder<T>(m_value);
        }

        T GetValue()const
        {
            return m_value;
        }
    private:
        T m_value;
    };

    /*any ���ģ�嶨�庯��   ******************************************************************************************/

    /// <summary>
    /// ���캯��
    /// </summary>
    /// <typeparam name="ValueType"></typeparam>
    /// <param name="value"></param>
    template<typename ValueType>
    Any::Any(const ValueType& value)
    {
        m_pValue = new Holder<ValueType>(value);
    }
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
    /// <summary>
    /// ��ֵ��������أ��ɸı����ж��󣬹����¶���
    /// </summary>
    /// <typeparam name="ValueType"></typeparam>
    /// <param name="value"></param>
    /// <returns></returns>
    template<typename ValueType>
    Any& Any::operator=(const ValueType& value)
    {
        Any tmp(value);
        //ɾ������ľ���ֵָ��
        if (m_pValue)
        {
            delete m_pValue;
        }
        m_pValue = tmp.GetHolderPointer();//���¸�ֵ�¶���
        tmp.SetHolderPointer(nullptr);//����Ϊnull ����ʱ��������ʱ������������delete��֧
        return *this;
    }
    /// <summary>
    /// ת��Ϊ��Ӧ���͵�ָ��
    /// </summary>
    /// <typeparam name="ValueType"></typeparam>
    /// <returns></returns>
    template<typename ValueType>
    ValueType* Any::anyPointCast()
    {
        Holder<ValueType>* p = dynamic_cast<Holder<ValueType>*>(m_pValue);
        return p ? &(p->GetValue()) : nullptr;
    }
    /// <summary>
    /// ת��Ϊ��Ӧ���͵�����
    /// </summary>
    /// <typeparam name="ValueType"></typeparam>
    /// <returns></returns>
    template<typename ValueType>
    ValueType& Any::anyRefCast()
    {
        return (dynamic_cast<Holder<ValueType>&>(*m_pValue)).GetValue();
    }
}