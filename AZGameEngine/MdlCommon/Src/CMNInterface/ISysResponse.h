#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
#include <any>
/*
约定，系统响应的内存管理由发起方申请，接收方销毁
约定，所有进行通讯的系统响应，均由智能指针管理

*/

namespace MdlCommonNS
{
	//系统级别响应
	class MdlCommonDLLAPI ISysResponse
	{
	public:
		virtual ~ISysResponse() = 0;
	public:
		//约定获取任意类型数据的方法
		virtual std::any& GetData()const = 0;
	};
}