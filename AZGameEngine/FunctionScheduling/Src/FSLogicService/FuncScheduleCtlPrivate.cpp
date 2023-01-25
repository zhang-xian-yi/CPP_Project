#include "FuncScheduleCtlPrivate.h"
#include <memory> //unique_ptr
#include <string>//字符串
#include <tuple>//元组
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"//默认请求和响应
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNServices/ServiceContainerSingle.h"//业务容器
using namespace MdlCommonNS;

namespace FuncScheduleNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	FuncScheduleCtlPrivate::FuncScheduleCtlPrivate()
		:m_pCmdServiceMap(new std::map<MdlCommonNS::ECommand, std::unique_ptr<ICmdService>>()),
		 m_pFuncServiceMap(new std::map<MdlCommonNS::EModuleType, std::unique_ptr<IFuncService>>())
	{

	}
	/// <summary>
	/// 析构函数
	/// </summary>
	FuncScheduleCtlPrivate::~FuncScheduleCtlPrivate()
	{
		if (m_pCmdServiceMap)
		{
			m_pCmdServiceMap->clear();
			delete m_pCmdServiceMap;
		}
		if (m_pFuncServiceMap)
		{
			m_pFuncServiceMap->clear();
			delete m_pFuncServiceMap;
		}
	}
	/// <summary>
	/// 命令业务逻辑
	/// </summary>
	/// <param name="cmd"></param>
	/// <returns></returns>
	std::unique_ptr<MdlCommonNS::ISysResponse> FuncScheduleCtlPrivate::SwitchCmdService(MdlCommonNS::ECommand cmd)
	{
		auto find = m_pCmdServiceMap->find(cmd);
		//构造返回参数
		std::any data ;
		if (find != m_pCmdServiceMap->end())
		{
			//执行指定的业务逻辑
			find->second->DoService();
			//构造返回参数
			data = std::tuple<bool, std::string>(true, "");
		}
		else
		{
			//构造返回参数 没有找到对应的命令程序
			data = std::tuple<bool,std::string>(false,"");
		}
		//构造返回参数
		auto pResult = new MdlCommonNS::DefSysResponse(data);
		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}

	/// <summary>
	/// 功能调度业务逻辑
	/// </summary>
	/// <param name="mdlTpye"></param>
	/// <param name="para"></param>
	/// <returns></returns>
	std::unique_ptr<MdlCommonNS::ISysResponse> FuncScheduleCtlPrivate::SwitchFuncService(MdlCommonNS::EModuleType mdlTpye, const std::unique_ptr<MdlCommonNS::ISysRequest>& para)
	{
		auto find = m_pFuncServiceMap->find(mdlTpye);
		//构造返回参数
		std::any data;
		if (find != m_pFuncServiceMap->end())
		{
			//执行指定的业务逻辑
			find->second->DoService(para);
			//构造返回参数
			data = std::tuple<bool, std::string>(true, "");
		}
		else
		{
			//构造返回参数
			data = std::tuple<bool, std::string>(false, "");
		}
		//构造返回参数
		auto pResult = new MdlCommonNS::DefSysResponse(data);
		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}

}

