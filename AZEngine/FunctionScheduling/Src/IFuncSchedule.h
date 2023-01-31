#pragma once
#include <any>
#include "CMNMEnum/Command/ECommand.h"
namespace FuncScheduleNS
{
	class IFuncSchedule
	{
	public:
		virtual std::any ExecuteCmd(MdlCommonNS::ECommand cmd) = 0;
	};
}