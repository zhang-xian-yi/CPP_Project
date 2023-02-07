#pragma once
#include "EventDrivenSystem/Src/ISystemEvent.h"//IDispatch,IRegister

namespace EventCommonNS
{
	class ISysEvent; //事件接口
	enum class ESysEventId :unsigned short;
}
namespace AZGameMainApp
{
	//事件服务
	class EventService
	{
	public:
		EventService();
		~EventService() ;
	public:
		bool HandleEvent(EventCommonNS::ISysEvent& eve);

		//绑定事件处理机制
		template<typename Func>
		void BindEventResponse(EventCommonNS::ESysEventId eid, const Func& func)
		{
			//绑定与注册
			this->m_pRegister->Register<Func>(eid, func);
		}
	private:
		bool SwitchEventIDHandle(EventCommonNS::ISysEvent& eve);
	private:
		EventDrivenSysNS::IDispatch* m_pDispatch;
		EventDrivenSysNS::IRegister* m_pRegister;
	};
}
