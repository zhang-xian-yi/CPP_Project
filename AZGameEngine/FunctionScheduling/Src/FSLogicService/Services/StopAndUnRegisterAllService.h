#pragma once
#include "FSLogicService/IService.h"

namespace FuncScheduleNS
{
	/// <summary>
	/// 初始化以及注册所有功能模块的业务逻辑
	/// </summary>
	class StopAndUnRegisterAllService :public ICmdService
	{
	public:
		StopAndUnRegisterAllService() = default;
		virtual ~StopAndUnRegisterAllService() = default;
	public:
		//执行业务逻辑入口函数
		virtual void DoService();
	};
}

