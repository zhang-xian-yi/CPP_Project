#pragma once
#include "EventDrivenSystem/Src/ISystemEvent.h"//IDispatch,IRegister

namespace LayerCommonNS
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
		bool HandleEvent(LayerCommonNS::ISysEvent& eve);

		//绑定事件处理机制
		template<typename Func>
		void BindEventResponse(LayerCommonNS::ESysEventId eid, const Func& func)
		{
			//绑定与注册
			this->m_pRegister->Register<Func>(eid, func);
		}
	private:
		bool SwitchEventIDHandle(LayerCommonNS::ISysEvent& eve);
	private:
		EventDrivenSysNS::IDispatch* m_pDispatch;
		EventDrivenSysNS::IRegister* m_pRegister;
	};
}
