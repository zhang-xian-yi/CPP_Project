#include "EventService.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "LayerCommon/Src/SysEvents/ISysEvent.h"//ϵͳid
#include "LayerCommon/Src/SysEvents.h"//�����¼�
namespace AZGameMainApp
{
	EventService::EventService()
		:m_pDispatch(nullptr),
		 m_pRegister(nullptr)
	{
		//�¼��ɷ�
		auto pEDS = MdlCommonNS::ServiceContainerSingle::GetInstance().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_EventDrivenSys_Type);
		if (pEDS.has_value())
		{
			m_pDispatch = pEDS.value()->ConvertType<EventDrivenSysNS::IDispatch*>();
			m_pRegister = pEDS.value()->ConvertType<EventDrivenSysNS::IRegister*>();
		}
	}
	EventService::~EventService()
	{
		//m_pDispatch �Ƿ��������ڲ�ָ�� �����ͷ�
	}
	/// <summary>
	/// ����
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