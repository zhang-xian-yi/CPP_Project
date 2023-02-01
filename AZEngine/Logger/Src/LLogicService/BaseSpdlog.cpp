#include "BaseSpdlog.h"
namespace LoggerNS
{
	OptLogBase::~OptLogBase()
	{
		DestroyLogger();
	}

	/* ������־�Ĵ�ӡ���� */
	void OptLogBase::SetPrintLevel(print_level lvl)
	{
		m_pLogger->set_level(lvl);
	}
	//��ȡ��־��¼
	std::shared_ptr<spdlog::logger> OptLogBase::GetLogger()
	{
		return m_pLogger;
	}
	/* ����logger */
	void OptLogBase::DestroyLogger()
	{
		spdlog::drop(m_pLogger->name());
	}
}