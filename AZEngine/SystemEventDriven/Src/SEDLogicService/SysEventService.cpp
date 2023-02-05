#include "SysEventService.h"
#include "SystemEventDriven/Src/SEDCommon/SEDCore.h"
namespace SysEventDNS
{
	//�����¼������ռ�
	using namespace EventCommonNS;

	SysEventService::SysEventService()
		:m_pEventHandlerMap(new std::unordered_map<ESysEventId, std::list<EveHandlerFN>*>())
	{
	}

	SysEventService::~SysEventService()
	{
		if (m_pEventHandlerMap)
		{
			//ɾ��
			for (auto[key,val] :*m_pEventHandlerMap)
			{
				delete val;
			}
			//����map
			delete m_pEventHandlerMap;
			m_pEventHandlerMap = nullptr;
		}
	}

	bool SysEventService::BindEventHandlerList(ESysEventId eveId, EveHandlerFN handler)
	{
		if (m_pEventHandlerMap->find(eveId) != m_pEventHandlerMap->end())
		{
			//����
			auto list = m_pEventHandlerMap->at(eveId);
			list->emplace_back(handler);//�����Ӵ�����
		}
		else
		{
			auto list = new std::list<EveHandlerFN>();
			list->emplace_back(handler);//�����Ӵ�����
			//���������ݼ�¼��
			m_pEventHandlerMap->insert(std::make_pair(eveId, list));
		}
		return true;
	}

	bool SysEventService::HandleEvent(ESysEventId eveId, IEvent& pEve)
	{
		if (m_pEventHandlerMap->find(eveId) != m_pEventHandlerMap->end())
		{
			//����
			auto list = m_pEventHandlerMap->at(eveId);
			for (auto& handlerFN : *list)
			{
#ifdef _DEBUG
				FormatLog("onevent id:{0}",eveId);
#endif // _DEBUG
				//�����¼�
				handlerFN(pEve);
			}
			return true;
		}
		return false;
	}



}
