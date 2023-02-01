#pragma once
#include <memory>
#include <string>
#include <filesystem>
#include "spdlog/spdlog.h"

#define LOG_LEVEL_TRACE spdlog::level::trace
#define LOG_LEVEL_DEBUG spdlog::level::debug
#define LOG_LEVEL_INFO spdlog::level::info
#define LOG_LEVEL_WARN spdlog::level::warn
#define LOG_LEVEL_ERROR spdlog::level::err
#define LOG_LEVEL_CRITICAL spdlog::level::critical
#define LOG_LEVEL_OFF spdlog::level::off

namespace LoggerNS
{
	using print_level = spdlog::level::level_enum;    //变量重命名
	using format_string = spdlog::string_view_t;

	class OptLogBase
	{
	protected:
		std::shared_ptr<spdlog::logger> m_pLogger;//日志记录器
	public:
		//生成输出目标，可能是文件，也可能是控制台
		virtual void AutoGenerateOutTarget() = 0;
		//创建日志记录器，约定为子类实现
		virtual void CreateLogger() = 0;
		//虚析构函数
		virtual ~OptLogBase() = 0;
	public:
		/* 设置日志的打印级别 */
		void SetPrintLevel(print_level lvl);
		//获取日志记录
		std::shared_ptr<spdlog::logger> GetLogger();
		/* 销毁logger */
		void DestroyLogger();
	};
}