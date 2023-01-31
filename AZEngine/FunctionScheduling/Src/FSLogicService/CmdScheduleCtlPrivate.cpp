#include "CmdScheduleCtlPrivate.h"
#include <memory> //unique_ptr
#include <string>//字符串
#include <tuple>//元组
#include "CMNServices/Container/ServiceContainerSingle.h"//业务容器
#include "CMNInterface/IMdlService.h"
#include "CMNMEnum/Command/ECommand.h"
#include "CMNMEnum/ModuelType/EModuleType.h"
#include "Services/InitAndRegisterAllService.h"//初始化所有的业务
#include "Services/StopAndUnRegisterAllService.h"//停止所有的业务
namespace FuncScheduleNS
{
	using namespace MdlCommonNS;
	/// <summary>
	/// 构造函数
	/// </summary>
	CmdScheduleCtlPrivate::CmdScheduleCtlPrivate()
		:m_pCmdServiceMap(new std::unordered_map<MdlCommonNS::ECommand, ICmdService*>())
	{
		InitData();
	}
	/// <summary>
	/// 析构函数
	/// </summary>
	CmdScheduleCtlPrivate::~CmdScheduleCtlPrivate()
	{
		if (m_pCmdServiceMap)
		{
			//结构化绑定 并遍历命令map 注意C17标准才支持结构化绑定
			for (auto&[cmd,inter] : *m_pCmdServiceMap)
			{
				delete inter;//删除创建的实例
			}
			m_pCmdServiceMap->clear();
			delete m_pCmdServiceMap;
		}
	}
	/// <summary>
	/// 命令业务逻辑
	/// </summary>
	/// <param name="cmd"></param>
	/// <returns></returns>
	std::any CmdScheduleCtlPrivate::SwitchCmdService(MdlCommonNS::ECommand cmd)
	{
		auto find = m_pCmdServiceMap->find(cmd);
		if (find != m_pCmdServiceMap->end())
		{
			//执行指定的业务逻辑
			find->second->DoService();
			//构造返回参数
			return std::tuple<bool, std::string>(true, "");
		}
		else
		{
			//构造返回参数 没有找到对应的命令程序
			return std::tuple<bool,std::string>(false,"");
		}
	}

	/// <summary>
	/// 初始化容器中数据
	/// </summary>
	void CmdScheduleCtlPrivate::InitData()
	{
		m_pCmdServiceMap->insert(std::make_pair(ECommand::E_InitAllFunction, new InitAndRegisterAllService()));
		m_pCmdServiceMap->insert(std::make_pair(ECommand::E_DestoryAllFunction, new StopAndUnRegisterAllService()));
	}

}

