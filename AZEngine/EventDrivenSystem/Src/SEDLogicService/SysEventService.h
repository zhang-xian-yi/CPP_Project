#pragma once
#include <unordered_map>
#include <list>
#include "EventDrivenSystem/Src/ISystemEvent.h"
namespace EventDrivenSysNS
{
	class BEventFunc;//���������¼��������Ļ���

	/// <summary>
	/// �ṩϵͳ�¼��ķ���
	/// </summary>
	class SysEventService
	{
	public:
		SysEventService();
		~SysEventService();

	public:
		//���¼�ID ���¼�����������ϵ
		bool BindEventHandlerList(EventCommonNS::ESysEventId eveId, BEventFunc* eFunc);
		//�����¼�
		BEventFunc* GetEventFunc(EventCommonNS::ESysEventId eveId);
	private:
		std::unordered_map<EventCommonNS::ESysEventId, BEventFunc*>* m_pEventHandlerMap;
	};
}


