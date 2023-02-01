#include "DateTimeUtil.h"
#include <filesystem>
namespace MdlCommonNS
{
	std::string DateTimeUtil::GetDayTime()
	{
		return GetTime("%Y-%m-%d");
	}

	/// <summary>
	/// 内部获取事件格式的通用函数
	/// </summary>
	/// <param name="pattern"></param>
	/// <returns></returns>
	std::string DateTimeUtil::GetTime(const std::string&& pattern)
	{
		time_t timep;
		time(&timep);
		char tmp[32];
		struct tm CurrT;
		//获取当前事件
		localtime_s(&CurrT, &timep);
		//格式化
		strftime(tmp, sizeof(tmp), pattern.c_str(), &CurrT);
		return std::string(tmp);
	}
}

