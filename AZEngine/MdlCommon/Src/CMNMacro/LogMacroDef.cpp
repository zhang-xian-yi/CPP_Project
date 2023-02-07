#include "LogMacroDef.h"
#include "Logger/Src/ILogger.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"

namespace MdlCommonNS
{
	/// <summary>
	/// 向日志中打印关键信息
	/// </summary>
	/// <param name="msg"></param>
	void LogMsgOSAsync(LoggerNS::ELogLevel logLv, const char* msg)
	{
		auto iLogS = MdlCommonNS::ServiceContainerSingle::GetInstance().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_Logger_Type);
		if (iLogS.has_value())
		{
			auto prunlog = iLogS.value()->ConvertType<LoggerNS::IFileLogger*>();
			prunlog->LogFileMsgAsync(logLv, msg);
			auto pstdoutlog = iLogS.value()->ConvertType<LoggerNS::IStdoutLogger*>();
			pstdoutlog->LogStdoutMsgAsync(logLv, msg);
		}
	}
}