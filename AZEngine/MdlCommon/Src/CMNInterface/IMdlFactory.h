#pragma once
//定义所有功能模块的工厂类约束
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
#include <CMNInterface/IMdlOperat.h>
#include <CMNInterface/IMdlService.h>
namespace MdlCommonNS
{
	//模块业务逻辑接口
	class MdlCommonDLLAPI IMdlFactory
	{
	public:
		virtual ~IMdlFactory() = 0;
	public:
		//这里Get 方法的实现必须存在构造子类实例的语句，不能为const，所以工厂指针也不能是const
		//这里不适用智能指针，因为模块和控制均是unique_ptr 进行管理
		virtual MdlCommonNS::IMdlService* CreateServiceInstance() = 0;
		virtual MdlCommonNS::IMdlOperat*  CreateModuleInstance() = 0;
	};
}