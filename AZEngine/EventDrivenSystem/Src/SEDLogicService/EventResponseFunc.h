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
	/// 可变函数参数
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
		/// 执行响应函数参数
		/// </summary>
		/// <param name="...args"></param>
		/// <returns></returns>
		RetType InvokeFunc(ArgsTypes&& ...args)
		{
			//执行保存的函数
			return m_func(std::forward<ArgsTypes>(args)...);
		}
	private:
		EveRepFunc m_func;//保存的事件响应函数
	};


}