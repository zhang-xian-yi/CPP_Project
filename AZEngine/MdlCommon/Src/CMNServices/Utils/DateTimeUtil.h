#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏

namespace MdlCommonNS
{
	/// <summary>
	/// 事件相关的方法函数
	/// </summary>
	class MdlCommonDLLAPI DateTimeUtil
	{
	public:
		static std::string GetDayTime();
	private:
		static std::string GetTime(const std::string&& pattern);
	};
}