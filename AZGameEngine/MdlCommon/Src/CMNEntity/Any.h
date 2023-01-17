#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏

namespace MdlCommonNS
{	
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
	public:
		T m_value;
	};
}

namespace MdlCommonNS
{
	/// <summary>
	/// 任意类型的数据，一般用作返回值
	/// </summary>
	class MdlCommonDLLAPI Any
	{
	public:
		//拷贝构造函数
		Any(const Any& any);
		//析构函数
		~Any();
	public:
		//模板的任意类型构造函数
		template<typename ValueType>
		Any(const ValueType& value)
		{
			m_pValue = new Holder<ValueType>(value);
		}
		//赋值运算符
		template<typename ValueType>
		Any& operator=(const ValueType& value)
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
		//值类型的指针转换
		template<typename ValueType>
		ValueType* AnyPointCast()
		{
			Holder<ValueType>* p = dynamic_cast<Holder<ValueType>*>(m_pValue);
			return p ? &(p->m_value) : nullptr;
		}
		//值类型的引用转换
		template<typename ValueType>
		ValueType& AnyRefCast()
		{
			return (dynamic_cast<Holder<ValueType>&>(*m_pValue)).m_value;
		}
	public:
		/*Get and Set  方法一般是函数内部调用，但必须公开，所以外部尽量不调用该方法  ********************************/
		//获取私有成员value的指针
		BaseHolder* GetHolderPointer()const;
		//设置私有成员value的指针
		void SetHolderPointer(BaseHolder* pointer);
	private:
		BaseHolder* m_pValue;
	};

}

