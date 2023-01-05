#pragma once

//定义所有功能模块的业务逻辑执行入口
#include <Common/ExportMarcoDefine.h> //导出宏
#include <Interface/ISysRequest.h>
#include <Interface/ISysResponse.h>
namespace CommonNS
{
	//模块业务逻辑接口
	class IMdlService
	{
	public:
		//执行业务逻辑入口函数
		virtual ISysResponse* DoService(const ISysRequest& para) = 0;
	};
}