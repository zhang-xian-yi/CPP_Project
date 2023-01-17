#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������

namespace MdlCommonNS
{	
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
	public:
		T m_value;
	};
}

namespace MdlCommonNS
{
	/// <summary>
	/// �������͵����ݣ�һ����������ֵ
	/// </summary>
	class MdlCommonDLLAPI Any
	{
	public:
		//�������캯��
		Any(const Any& any);
		//��������
		~Any();
	public:
		//ģ����������͹��캯��
		template<typename ValueType>
		Any(const ValueType& value)
		{
			m_pValue = new Holder<ValueType>(value);
		}
		//��ֵ�����
		template<typename ValueType>
		Any& operator=(const ValueType& value)
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
		//ֵ���͵�ָ��ת��
		template<typename ValueType>
		ValueType* AnyPointCast()
		{
			Holder<ValueType>* p = dynamic_cast<Holder<ValueType>*>(m_pValue);
			return p ? &(p->m_value) : nullptr;
		}
		//ֵ���͵�����ת��
		template<typename ValueType>
		ValueType& AnyRefCast()
		{
			return (dynamic_cast<Holder<ValueType>&>(*m_pValue)).m_value;
		}
	public:
		/*Get and Set  ����һ���Ǻ����ڲ����ã������빫���������ⲿ���������ø÷���  ********************************/
		//��ȡ˽�г�Աvalue��ָ��
		BaseHolder* GetHolderPointer()const;
		//����˽�г�Աvalue��ָ��
		void SetHolderPointer(BaseHolder* pointer);
	private:
		BaseHolder* m_pValue;
	};

}

