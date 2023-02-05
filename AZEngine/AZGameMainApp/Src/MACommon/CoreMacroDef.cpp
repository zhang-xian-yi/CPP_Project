#include "CoreMacroDef.h"
#include "Logger/Src/ILogger.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"

namespace AZGameMainApp
{
	/// <summary>
	/// 向日志中打印关键信息
	/// </summary>
	/// <param name="msg"></param>
	void LogMsgOSAsync(const char* msg)
	{
		auto iLogS = MdlCommonNS::ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_Logger_Type);
		if (iLogS.has_value())
		{
			auto prunlog = iLogS.value()->ConvertType<LoggerNS::IFileLogger*>();
			prunlog->LogFileMsgAsync(LoggerNS::ELogLevel::E_Error_LV, msg);
			auto pstdoutlog = iLogS.value()->ConvertType<LoggerNS::IStdoutLogger*>();
			pstdoutlog->LogStdoutMsgAsync(LoggerNS::ELogLevel::E_Error_LV, msg);
		}
	}
}

