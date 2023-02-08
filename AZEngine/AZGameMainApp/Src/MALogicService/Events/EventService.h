#pragma once
#include "EventDrivenSystem/Src/ISystemEvent.h"//IDispatch,IRegister

namespace LayerCommonNS
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
		bool HandleEvent(LayerCommonNS::ISysEvent& eve);

		//���¼��������
		template<typename Func>
		void BindEventResponse(LayerCommonNS::ESysEventId eid, const Func& func)
		{
			//����ע��
			this->m_pRegister->Register<Func>(eid, func);
		}
	private:
		bool SwitchEventIDHandle(LayerCommonNS::ISysEvent& eve);
	private:
		EventDrivenSysNS::IDispatch* m_pDispatch;
		EventDrivenSysNS::IRegister* m_pRegister;
	};
}
