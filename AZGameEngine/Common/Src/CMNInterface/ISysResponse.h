#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏


namespace CommonNS
{
	//系统级别响应
	class CommonDLLAPI ISysResponse
	{
	public:
		virtual ~ISysResponse() = 0;
	public:
		//约定所有的系统响应数据必须实现此方法
		virtual bool IsValid() const = 0;
	};
}