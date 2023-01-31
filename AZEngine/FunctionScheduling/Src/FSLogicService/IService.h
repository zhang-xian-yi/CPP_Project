#pragma once
#include <memory>//unique_ptr 引入

namespace MdlCommonNS
{
	//前置声明
	enum class EModuleType :unsigned char;
	class IMdlFactory;
}

namespace FuncScheduleNS
{
	/*
	实现此Iservice 接口的子类，每个子类均对应指定参数命令
	参数命令由MdlCommon模块的 ECommand 的枚举类进行维护
	ECommand与子类实例的关系 由FuncScheduleCtlPrivate类进行map方式的维护
	*/

	class ICmdService
	{
	public:
		virtual ~ICmdService() = 0;
	public:
		//执行业务逻辑入口函数
		virtual void DoService() = 0;
	};

}