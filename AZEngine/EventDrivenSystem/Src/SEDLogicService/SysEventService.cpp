#include "SysEventService.h"
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "Logger/Src/ILogger.h"
#include "EventResponseFunc.h"
namespace EventDrivenSysNS
{
	//�����¼������ռ�
	using namespace EventCommonNS;

	SysEventService::SysEventService()
		:m_pEventHandlerMap(new std::unordered_map<ESysEventId, BEventFunc*>())
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

	/// <summary>
	/// �����¼��봦��id�Ĺ�ϵ
	/// </summary>
	/// <param name="eveId"></param>
	/// <param name="eFunc"></param>
	/// <returns></returns>
	bool SysEventService::BindEventHandlerList(EventCommonNS::ESysEventId eveId, BEventFunc* eFunc)
	{
		if (!m_pEventHandlerMap->count(eveId))
		{
			//������-���
			m_pEventHandlerMap->insert(std::make_pair(eveId, eFunc));
		}
		else
		{
			//���ڸ���
			(*m_pEventHandlerMap)[eveId] = eFunc;
		}
		return true;
	}

	//��������ָ��
	typedef bool (*EveHandlerFN)(EventCommonNS::ISysEvent&);

	/// <summary>
	/// ��ȡʱ�䴦����
	/// </summary>
	/// <param name="eveId"></param>
	/// <returns></returns>
	BEventFunc* SysEventService::GetEventFunc(EventCommonNS::ESysEventId eveId)
	{
		if (m_pEventHandlerMap->count(eveId)) //count ����eveid���ڵĸ��������Ϊ1�ͱ�ʾ���ڣ���Ϊtrue��
		{
			//����
			return m_pEventHandlerMap->at(eveId);
		}
		return nullptr;
	}



}
