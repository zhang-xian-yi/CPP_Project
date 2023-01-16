#include "MdlScheduleFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/IMdlOperat.h"
//实现类
#include <MSMControl/MdlOperatControl.h>
#include <MSMControl/MdlScheduleControl.h>
namespace MdlScheduleNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	MdlScheduleFactory::MdlScheduleFactory()
		:m_pService(nullptr), m_pModule(nullptr)
	{
	}
	/// <summary>
	/// 析构函数
	/// </summary>
	MdlScheduleFactory::~MdlScheduleFactory()
	{
		if (m_pService != nullptr)
		{
			//销毁日志
			delete m_pService;
			m_pService = nullptr;
		}
		if (m_pModule != nullptr)
		{
			//销毁日志
			delete m_pModule;
			m_pModule = nullptr;
		}
	}

	MdlCommonNS::IMdlService* MdlScheduleFactory::GetServiceInstance()
	{
		if (m_pService == nullptr)
		{
			//初始化日志 
			m_pService = new MdlScheduleNS::MdlScheduleControl();
		}
		return m_pService;
	}
	MdlCommonNS::IMdlOperat* MdlScheduleFactory::GetModuleInstance()
	{
		if (m_pModule == nullptr)
		{
			//初始化日志 
			m_pModule = new MdlScheduleNS::MdlOperatControl();
		}
		return m_pModule;
	}
}