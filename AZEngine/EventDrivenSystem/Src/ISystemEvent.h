#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
#include "LayerCommon/Src/SysEvents/ISysEvent.h"
#include "LayerCommon/Src/SysEvents.h"
#include "SEDLogicService/EventResponseFunc.h"//BEventFunc

//�󶨱������¼���Ӧ����
#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace EventDrivenSysNS
{
	/// <summary>
	/// ���������¼�ID���¼�������
	/// </summary>
	class EventDrivenSysNSAPI IRegister
	{
	public:
		template<typename Func>
		bool Register(LayerCommonNS::ESysEventId eId,const Func& func)
		{
			//����ע��
			return RegisterPrivate(eId, new Func(func));
		}
	private:
		virtual bool RegisterPrivate(LayerCommonNS::ESysEventId eid, BEventFunc* eFunc) = 0;
	};

	/// <summary>
	/// ����ת���¼�
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
				//ִ��ָ������
				return pFunc->InvokeFunc(std::forward<ArgTypes>(args)...);
			}
			//����Ĭ��ֵ
			return RetType();
		}
	private:
		virtual BEventFunc* GetEventFunc(LayerCommonNS::ESysEventId eid) = 0;
	};
}