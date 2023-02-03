#pragma once
#include "SEDCommon/SEDExpMarcoDefine.h"
//�������¼�ȫ���������ⲿ
#include "SEDLogicService/Events/IEvent.h"
#include "SEDLogicService/Events/ApplicationEvent.h"
#include "SEDLogicService/Events/KeyboardEvent.h"
#include "SEDLogicService/Events/MouseEvent.h"
#include "SEDLogicService/Events/WindowEvent.h"
namespace SysEventDNS
{
	typedef bool (*EveHandlerFN)(IEvent*);

	struct EventHandler
	{
		EveHandlerFN func;
	};



	/// <summary>
	/// ���������¼�ID���¼�������
	/// </summary>
	class SysEventNSAPI IConnect
	{
	public:
		virtual bool Connect(ESysEventId eId, EventHandler handler) = 0;
	};

	/// <summary>
	/// ����ת���¼�
	/// </summary>
	class SysEventNSAPI IDispatch
	{
	public:
		virtual bool DispatchEvent(IEvent* eve) = 0;
	};
}