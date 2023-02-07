#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "EventCommon/Src/SysEvents/ISysEvent.h"
#include "EventCommon/Src/SysEvents.h"
#include "SEDLogicService/EventResponseFunc.h"//BEventFunc
namespace EventDrivenSysNS
{
	/// <summary>
	/// 负责链接事件ID和事件处理函数
	/// </summary>
	class EventDrivenSysNSAPI IRegister
	{
	public:
		template<typename Func>
		bool Register(EventCommonNS::ESysEventId eId,const Func& func)
		{
			//重新注册
			return RegisterPrivate(eId, new Func(func));
		}
	private:
		virtual bool RegisterPrivate(EventCommonNS::ESysEventId eid, BEventFunc* eFunc) = 0;
	};

	/// <summary>
	/// 负责转发事件
	/// </summary>
	class EventDrivenSysNSAPI IDispatch
	{
	public:
		template<typename RetType, typename... ArgTypes>
		RetType DispatchEvent(EventCommonNS::ESysEventId eid, ArgTypes... args )
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
		virtual BEventFunc* GetEventFunc(EventCommonNS::ESysEventId eid) = 0;
	};
}