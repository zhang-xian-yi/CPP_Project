#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
#include <any>
/*
约定，系统请求的内存管理由发起方申请，接收方销毁
约定，所有进行通讯的系统请求，均由智能指针管理

*/

namespace MdlCommonNS
{
	//系统级别请求
	class MdlCommonDLLAPI ISysRequest
	{
	public:
		virtual ~ISysRequest() = 0;
	public:
		//约定获取任意类型数据的方法
		virtual std::any& GetData()const = 0;
	};
}