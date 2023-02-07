#pragma once
#include <functional>

namespace EventDrivenSysNS
{
	class BEventFunc
	{
	public:
		virtual ~BEventFunc() {}
	};


	/// <summary>
	/// �ɱ亯������
	/// </summary>
	/// <typeparam name="RetType"></typeparam>
	/// <typeparam name="...ArgsTypes"></typeparam>
	template<typename RetType,typename... ArgsTypes>
	class EventResponseFunc:public BEventFunc
	{
		using EveRepFunc = std::function<RetType(ArgsTypes...)>;
	public:
		EventResponseFunc(EveRepFunc func)
			:m_func(func) 
		{

		}

		/// <summary>
		/// ִ����Ӧ��������
		/// </summary>
		/// <param name="...args"></param>
		/// <returns></returns>
		RetType InvokeFunc(ArgsTypes&& ...args)
		{
			//ִ�б���ĺ���
			return m_func(std::forward<ArgsTypes>(args)...);
		}
	private:
		EveRepFunc m_func;//������¼���Ӧ����
	};


}