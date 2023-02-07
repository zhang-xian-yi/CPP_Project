#include "SysEventService.h"
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "Logger/Src/ILogger.h"
namespace EventDrivenSysNS
{
	//公共事件命名空间
	using namespace EventCommonNS;

	SysEventService::SysEventService()
		:m_pEventHandlerMap(new std::unordered_map<ESysEventId, std::list<EveHandlerFN>*>())
	{
	}

	SysEventService::~SysEventService()
	{
		if (m_pEventHandlerMap)
		{
			//删除
			for (auto[key,val] :*m_pEventHandlerMap)
			{
				delete val;
			}
			//销毁map
			delete m_pEventHandlerMap;
			m_pEventHandlerMap = nullptr;
		}
	}

	bool SysEventService::BindEventHandlerList(ESysEventId eveId, EveHandlerFN handler)
	{
		if (m_pEventHandlerMap->find(eveId) != m_pEventHandlerMap->end())
		{
			//存在
			auto list = m_pEventHandlerMap->at(eveId);
			list->emplace_back(handler);//向后添加处理器
		}
		else
		{
			auto list = new std::list<EveHandlerFN>();
			list->emplace_back(handler);//向后添加处理器
			//保存在数据记录中
			m_pEventHandlerMap->insert(std::make_pair(eveId, list));
		}
		return true;
	}

	bool SysEventService::HandleEvent(IEvent& pEve)
	{
#ifdef _DEBUG
		MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV,"on event id:", std::string(pEve.GetName()));
#endif // _DEBUG

		auto eveId = pEve.GetEventId();
		if (m_pEventHandlerMap->find(eveId) != m_pEventHandlerMap->end())
		{
			//存在
			auto list = m_pEventHandlerMap->at(eveId);
			for (auto& handlerFN : *list)
			{
				//处理事件
				handlerFN(pEve);
			}
			return true;
		}
		return false;
	}



}
