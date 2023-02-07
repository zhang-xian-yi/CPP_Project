#include "SysEventService.h"
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "Logger/Src/ILogger.h"
#include "EventResponseFunc.h"
namespace EventDrivenSysNS
{
	//公共事件命名空间
	using namespace EventCommonNS;

	SysEventService::SysEventService()
		:m_pEventHandlerMap(new std::unordered_map<ESysEventId, BEventFunc*>())
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

	/// <summary>
	/// 保存事件与处理id的关系
	/// </summary>
	/// <param name="eveId"></param>
	/// <param name="eFunc"></param>
	/// <returns></returns>
	bool SysEventService::BindEventHandlerList(EventCommonNS::ESysEventId eveId, BEventFunc* eFunc)
	{
		if (!m_pEventHandlerMap->count(eveId))
		{
			//不存在-添加
			m_pEventHandlerMap->insert(std::make_pair(eveId, eFunc));
		}
		else
		{
			//存在覆盖
			(*m_pEventHandlerMap)[eveId] = eFunc;
		}
		return true;
	}

	//声明函数指针
	typedef bool (*EveHandlerFN)(EventCommonNS::ISysEvent&);

	/// <summary>
	/// 获取时间处理函数
	/// </summary>
	/// <param name="eveId"></param>
	/// <returns></returns>
	BEventFunc* SysEventService::GetEventFunc(EventCommonNS::ESysEventId eveId)
	{
		if (m_pEventHandlerMap->count(eveId)) //count 返回eveid存在的个数，如果为1就表示存在，就为true，
		{
			//存在
			return m_pEventHandlerMap->at(eveId);
		}
		return nullptr;
	}



}
