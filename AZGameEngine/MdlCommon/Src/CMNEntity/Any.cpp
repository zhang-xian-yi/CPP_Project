#include "Any.h"

namespace MdlCommonNS
{
    //任意值的接口
    class BaseHolder
    {
    public:
        BaseHolder() { }
        virtual ~BaseHolder() { }
        virtual BaseHolder* clone() = 0;
    };

    //任意值的实现模板类
    template<typename T>
    class Holder : public BaseHolder
    {
    public:
        Holder(const T& t) : m_value(t) {}
        ~Holder() {}
    public:
        BaseHolder* clone() override
        {
            //必须重新定义拷贝函数，否则delete基类指针时会两次释放从而崩溃
            return new Holder<T>(m_value);
        }

        T GetValue()const
        {
            return m_value;
        }
    private:
        T m_value;
    };

    /*any 类的模板定义函数   ******************************************************************************************/

    /// <summary>
    /// 构造函数
    /// </summary>
    /// <typeparam name="ValueType"></typeparam>
    /// <param name="value"></param>
    template<typename ValueType>
    Any::Any(const ValueType& value)
    {
        m_pValue = new Holder<ValueType>(value);
    }
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
    /// <summary>
    /// 赋值运算符重载，可改变已有对象，构造新对象
    /// </summary>
    /// <typeparam name="ValueType"></typeparam>
    /// <param name="value"></param>
    /// <returns></returns>
    template<typename ValueType>
    Any& Any::operator=(const ValueType& value)
    {
        Any tmp(value);
        //删除此类的旧有值指针
        if (m_pValue)
        {
            delete m_pValue;
        }
        m_pValue = tmp.GetHolderPointer();//重新赋值新对象
        tmp.SetHolderPointer(nullptr);//设置为null ，临时对象销毁时析构函数不走delete分支
        return *this;
    }
    /// <summary>
    /// 转换为对应类型的指针
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
    /// 转换为对应类型的引用
    /// </summary>
    /// <typeparam name="ValueType"></typeparam>
    /// <returns></returns>
    template<typename ValueType>
    ValueType& Any::anyRefCast()
    {
        return (dynamic_cast<Holder<ValueType>&>(*m_pValue)).GetValue();
    }
}