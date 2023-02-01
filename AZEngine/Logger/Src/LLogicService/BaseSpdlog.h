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
	using print_level = spdlog::level::level_enum;    //����������
	using format_string = spdlog::string_view_t;

	class OptLogBase
	{
	protected:
		std::shared_ptr<spdlog::logger> m_pLogger;//��־��¼��
	public:
		//�������Ŀ�꣬�������ļ���Ҳ�����ǿ���̨
		virtual void AutoGenerateOutTarget() = 0;
		//������־��¼����Լ��Ϊ����ʵ��
		virtual void CreateLogger() = 0;
		//����������
		virtual ~OptLogBase() = 0;
	public:
		/* ������־�Ĵ�ӡ���� */
		void SetPrintLevel(print_level lvl);
		//��ȡ��־��¼
		std::shared_ptr<spdlog::logger> GetLogger();
		/* ����logger */
		void DestroyLogger();
	};
}