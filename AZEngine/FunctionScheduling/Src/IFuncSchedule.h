#pragma once
#include <any>
#include "MdlCommon/Src/CMNMEnum/Command/ECommand.h"
namespace FuncScheduleNS
{
	/// <summary>
	/// ������ȹ���
	/// </summary>
	class IFuncSchedule
	{
	public:
		virtual std::any ExecuteCmd(MdlCommonNS::ECommand cmd) = 0;
	};
}