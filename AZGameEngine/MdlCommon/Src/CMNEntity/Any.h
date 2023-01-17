#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������

namespace MdlCommonNS
{
	//ǰ������
	class BaseHolder;

	/// <summary>
	/// �������͵����ݣ�һ����������ֵ
	/// </summary>
	class MdlCommonDLLAPI Any
	{
	public:
		//ģ����������͹��캯��
		template<typename ValueType>
		Any(const ValueType& value);
		//�������캯��
		Any(const Any& any);
		//��������
		~Any();
		//��ֵ�����
		template<typename ValueType>
		Any& operator=(const ValueType& value);
	public:
		//ֵ���͵�ָ��ת��
		template<typename ValueType>
		ValueType* anyPointCast();
		//ֵ���͵�����ת��
		template<typename ValueType>
		ValueType& anyRefCast();
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

