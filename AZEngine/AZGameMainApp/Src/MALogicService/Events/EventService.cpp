#include "EventService.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "LayerCommon/Src/SysEvents/ISysEvent.h"//系统id
#include "LayerCommon/Src/SysEvents.h"//所有事件
namespace AZGameMainApp
{
	EventService::EventService()
		:m_pDispatch(nullptr),
		 m_pRegister(nullptr)
	{
		//事件派发
		auto pEDS = MdlCommonNS::ServiceContainerSingle::GetInstance().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_EventDrivenSys_Type);
		if (pEDS.has_value())
		{
			m_pDispatch = pEDS.value()->ConvertType<EventDrivenSysNS::IDispatch*>();
			m_pRegister = pEDS.value()->ConvertType<EventDrivenSysNS::IRegister*>();
		}
	}
	EventService::~EventService()
	{
		//m_pDispatch 是服务容器内部指针 无需释放
	}
	/// <summary>
	/// 处理
	/// </summary>
	/// <param name="eve"></param>
	/// <returns></returns>
	bool EventService::HandleEvent(LayerCommonNS::ISysEvent& eve)
	{
		bool ret = SwitchEventIDHandle(eve);

		return true;
	}
	bool EventService::SwitchEventIDHandle(LayerCommonNS::ISysEvent& eve)
	{
		auto id = eve.GetEventId();

		switch (id)
		{
		case LayerCommonNS::ESysEventId::WindowClose:
		{
			auto newEve = static_cast<LayerCommonNS::WindowCloseEvent&>(eve);
			return m_pDispatch->DispatchEvent<bool>(id, newEve);
		}
		case LayerCommonNS::ESysEventId::WindowResize:
		{
			auto newEve = static_cast<LayerCommonNS::WindowResizeEvent&>(eve);
			return m_pDispatch->DispatchEvent<bool>(id, newEve);
		}
		default:
			break;
		}
		return false;
	}
}