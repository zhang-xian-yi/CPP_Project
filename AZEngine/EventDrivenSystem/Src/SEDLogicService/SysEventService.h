#pragma once
#include <unordered_map>
#include <list>
#include "EventDrivenSystem/Src/ISystemEvent.h"
namespace SysEventDNS
{
	using namespace EventCommonNS;

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
		bool BindEventHandlerList(ESysEventId eveId, EveHandlerFN handler);
		//�����¼�
		bool HandleEvent(IEvent& pEve);
	private:
		std::unordered_map<ESysEventId, std::list<EveHandlerFN>*>* m_pEventHandlerMap;
	};
}


