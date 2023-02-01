#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
namespace MdlCommonNS
{
	/// <summary>
/// 事件相关的方法函数
/// </summary>
	class MdlCommonDLLAPI PathUtil
	{
	public:
		static std::string GetExecutePath();
	};
}