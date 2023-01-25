#pragma once

//定义所有功能模块的业务逻辑执行入口
#include <memory>
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
#include <CMNInterface/ISysRequest.h>
#include <CMNInterface/ISysResponse.h>

namespace MdlCommonNS
{
	//模块业务逻辑接口
	class MdlCommonDLLAPI IMdlService
	{
	public:
		virtual ~IMdlService() = 0;
	public:
		//执行业务逻辑入口函数,允许参数为空,智能指针实际上是指针，不存在拷贝复制的开销
		virtual std::unique_ptr<ISysResponse> DoService(const std::unique_ptr<ISysRequest>& para = nullptr) = 0;
	};
}