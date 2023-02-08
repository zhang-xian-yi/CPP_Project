#pragma once
#include <future>//异步执行头文件
#include "FSLogicService/IService.h"

namespace MdlCommonNS
{
	//前置声明
	enum class EModuleType :unsigned char;
	class IMdlFactory;
}

namespace FuncScheduleNS
{
	/// <summary>
	/// 初始化以及注册所有功能模块的业务逻辑
	/// </summary>
	class InitAndRegisterAllService:public ICmdService
	{
	public:
		InitAndRegisterAllService() = default;
		virtual ~InitAndRegisterAllService() = default;
	public:
		//执行业务逻辑入口函数
		virtual void DoService();
	private:
		//根据工厂对象创建与注册指定实例
		std::future<bool> InitAndRegisterMdlAsync(MdlCommonNS::EModuleType type, MdlCommonNS::IMdlFactory* factory);
		bool InitAndRegisterMdl(MdlCommonNS::EModuleType type, MdlCommonNS::IMdlFactory* factory);
	};
}


