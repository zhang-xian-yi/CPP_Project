#include "BaseSpdlog.h"
namespace LoggerNS
{
	OptLogBase::~OptLogBase()
	{
		DestroyLogger();
	}

	/* 设置日志的打印级别 */
	void OptLogBase::SetPrintLevel(print_level lvl)
	{
		m_pLogger->set_level(lvl);
	}
	//获取日志记录
	std::shared_ptr<spdlog::logger> OptLogBase::GetLogger()
	{
		return m_pLogger;
	}
	/* 销毁logger */
	void OptLogBase::DestroyLogger()
	{
		spdlog::drop(m_pLogger->name());
	}
}