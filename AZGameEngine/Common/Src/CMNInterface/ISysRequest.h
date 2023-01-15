#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏

namespace CommonNS
{
	//系统级别请求
	class CommonDLLAPI ISysRequest
	{
	public:
		virtual ~ISysRequest() = 0;
	public:
		//约定所有的系统请求数据必须实现此方法
		virtual bool IsValid()const = 0;
	};
}