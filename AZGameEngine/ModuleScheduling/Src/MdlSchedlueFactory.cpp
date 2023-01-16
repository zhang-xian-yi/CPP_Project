#include "MdlScheduleFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/IMdlOperat.h"
//ʵ����
#include <MSMControl/MdlOperatControl.h>
#include <MSMControl/MdlScheduleControl.h>
namespace MdlScheduleNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	MdlScheduleFactory::MdlScheduleFactory()
		:m_pService(nullptr), m_pModule(nullptr)
	{
	}
	/// <summary>
	/// ��������
	/// </summary>
	MdlScheduleFactory::~MdlScheduleFactory()
	{
		if (m_pService != nullptr)
		{
			//������־
			delete m_pService;
			m_pService = nullptr;
		}
		if (m_pModule != nullptr)
		{
			//������־
			delete m_pModule;
			m_pModule = nullptr;
		}
	}

	MdlCommonNS::IMdlService* MdlScheduleFactory::GetServiceInstance()
	{
		if (m_pService == nullptr)
		{
			//��ʼ����־ 
			m_pService = new MdlScheduleNS::MdlScheduleControl();
		}
		return m_pService;
	}
	MdlCommonNS::IMdlOperat* MdlScheduleFactory::GetModuleInstance()
	{
		if (m_pModule == nullptr)
		{
			//��ʼ����־ 
			m_pModule = new MdlScheduleNS::MdlOperatControl();
		}
		return m_pModule;
	}
}