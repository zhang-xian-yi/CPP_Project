#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "LayerCommon/Src/SysEvents/ISysEvent.h"
#include "LayerCommon/Src/SysEvents.h"
#include "SEDLogicService/EventResponseFunc.h"//BEventFunc

//绑定本类中事件响应函数
#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace EventDrivenSysNS
{
	/// <summary>
	/// 负责链接事件ID和事件处理函数
	/// </summary>
	class EventDrivenSysNSAPI IRegister
	{
	public:
		template<typename Func>
		bool Register(LayerCommonNS::ESysEventId eId,const Func& func)
		{
			//重新注册
			return RegisterPrivate(eId, new Func(func));
		}
	private:
		virtual bool RegisterPrivate(LayerCommonNS::ESysEventId eid, BEventFunc* eFunc) = 0;
	};

	/// <summary>
	/// 负责转发事件
	/// </summary>
	class EventDrivenSysNSAPI IDispatch
	{
	public:
		template<typename RetType, typename... ArgTypes>
		RetType DispatchEvent(LayerCommonNS::ESysEventId eid, ArgTypes... args )
		{
			auto tmp = GetEventFunc(eid);
			EventResponseFunc<RetType, ArgTypes...>* pFunc = static_cast<EventResponseFunc<RetType, ArgTypes...>*>(tmp);
			if (pFunc)
			{
				//执行指定方法
				return pFunc->InvokeFunc(std::forward<ArgTypes>(args)...);
			}
			//返回默认值
			return RetType();
		}
	private:
		virtual BEventFunc* GetEventFunc(LayerCommonNS::ESysEventId eid) = 0;
	};
}