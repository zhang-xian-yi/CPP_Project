#pragma once
#include "EventDrivenSystem/Src/ISystemEvent.h"//IDispatch,IRegister

namespace EventCommonNS
{
	class ISysEvent; //�¼��ӿ�
	enum class ESysEventId :unsigned short;
}
namespace AZGameMainApp
{
	//�¼�����
	class EventService
	{
	public:
		EventService();
		~EventService() ;
	public:
		bool HandleEvent(EventCommonNS::ISysEvent& eve);

		//���¼��������
		template<typename Func>
		void BindEventResponse(EventCommonNS::ESysEventId eid, const Func& func)
		{
			//����ע��
			this->m_pRegister->Register<Func>(eid, func);
		}
	private:
		bool SwitchEventIDHandle(EventCommonNS::ISysEvent& eve);
	private:
		EventDrivenSysNS::IDispatch* m_pDispatch;
		EventDrivenSysNS::IRegister* m_pRegister;
	};
}
