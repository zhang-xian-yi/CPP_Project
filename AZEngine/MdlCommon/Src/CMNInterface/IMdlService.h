#pragma once

//定义所有功能模块的业务逻辑执行入口
#include <any>
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏

namespace MdlCommonNS
{
	//模块业务逻辑接口
	class MdlCommonDLLAPI IMdlService
	{
	public:
		virtual ~IMdlService() = 0;
	public:
		//将此类指针动态转换为模块的接口指针
		template<typename T>
		T ConvertType()
		{
			return dynamic_cast<T>(this);
		}
	};
}