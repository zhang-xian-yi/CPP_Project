#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏

/*
约定，系统请求的内存管理由发起方申请，接收方销毁
	  

*/

namespace MdlCommonNS
{
	//系统级别请求
	class MdlCommonDLLAPI ISysRequest
	{
	public:
		virtual ~ISysRequest() = 0;
	public:
		//约定所有的系统请求数据必须实现此方法
		virtual bool IsValid()const = 0;
	};
}