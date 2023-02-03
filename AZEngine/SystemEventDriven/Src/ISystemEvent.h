#pragma once
#include <functional>
#include "SEDCommon/SEDExpMarcoDefine.h"
//将所有事件全部开发给外部
#include "SEDLogicService/Events/IEvent.h"
#include "SEDLogicService/Events/ApplicationEvent.h"
#include "SEDLogicService/Events/KeyboardEvent.h"
#include "SEDLogicService/Events/MouseEvent.h"
#include "SEDLogicService/Events/WindowEvent.h"
namespace SysEventDNS
{
	/// <summary>
	/// 负责链接事件ID和事件处理函数
	/// </summary>
	class SysEventNSAPI IConnect
	{
	public:
		virtual bool Connect(ESysEventId eId,std::function<bool(IEvent*)> handler) = 0;
	};

	/// <summary>
	/// 负责转发事件
	/// </summary>
	class SysEventNSAPI IDispatch
	{
	public:
		virtual void DispatchEvent(IEvent* eve) = 0;
	};
}