#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "EventCommon/Src/SysEvents/ISysEvent.h"
#include "EventCommon/Src/SysEvents.h"
#include "SEDLogicService/EventResponseFunc.h"//BEventFunc
namespace EventDrivenSysNS
{
	/// <summary>
	/// ���������¼�ID���¼�������
	/// </summary>
	class EventDrivenSysNSAPI IRegister
	{
	public:
		template<typename Func>
		bool Register(EventCommonNS::ESysEventId eId,const Func& func)
		{
			//����ע��
			return RegisterPrivate(eId, new Func(func));
		}
	private:
		virtual bool RegisterPrivate(EventCommonNS::ESysEventId eid, BEventFunc* eFunc) = 0;
	};

	/// <summary>
	/// ����ת���¼�
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
				//ִ��ָ������
				return pFunc->InvokeFunc(std::forward<ArgTypes>(args)...);
			}
			//����Ĭ��ֵ
			return RetType();
		}
	private:
		virtual BEventFunc* GetEventFunc(EventCommonNS::ESysEventId eid) = 0;
	};
}