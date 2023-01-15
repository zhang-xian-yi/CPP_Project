#pragma once

//定义所有功能模块的业务逻辑执行入口
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
#include <CMNInterface/ISysRequest.h>
#include <CMNInterface/ISysResponse.h>
namespace CommonNS
{
	//模块业务逻辑接口
	class CommonDLLAPI IMdlService
	{
	public:
		virtual ~IMdlService() = 0;
	public:
		//执行业务逻辑入口函数,允许参数为空
		virtual ISysResponse* DoService(const ISysRequest* para) = 0;
	};
}