#pragma once
#include <string>
#include "MdlCommon/Src/CMNMacro/CMNExpMarcoDefine.h" //������
namespace MdlCommonNS
{
	/// <summary>
/// �¼���صķ�������
/// </summary>
	class MdlCommonDLLAPI PathUtil
	{
	public:
		static std::string GetExecutePath();
	};
}