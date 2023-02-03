#pragma once
#include <string>
#include "MdlCommon/Src/CMNMacro/CMNExpMarcoDefine.h" //������

namespace MdlCommonNS
{
	/// <summary>
	/// �¼���صķ�������
	/// </summary>
	class MdlCommonDLLAPI DateTimeUtil
	{
	public:
		static std::string GetDayTime();
	private:
		static std::string GetTime(const std::string&& pattern);
	};
}