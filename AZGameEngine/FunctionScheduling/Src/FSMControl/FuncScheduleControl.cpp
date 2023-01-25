#include "FuncScheduleControl.h"
#include <typeinfo>
#include "FSLogicService/FuncScheduleCtlPrivate.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"
#include "CMNMEnum/Command/ECommand.h"
#include "CMNMEnum/ModuelType/EModuleType.h"
namespace FuncScheduleNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	FuncScheduleControl::FuncScheduleControl()
		:m_pService(new FuncScheduleCtlPrivate())
	{
	}
	/// <summary>
	/// 析构函数
	/// </summary>
	FuncScheduleControl::~FuncScheduleControl()
	{
		if (m_pService != nullptr)
		{
			delete m_pService;
			m_pService = nullptr;
		}
	}
	/// <summary>
	/// 执行调度逻辑
	/// </summary>
	/// <param name="para"></param>
	/// <returns></returns>
	std::unique_ptr<MdlCommonNS::ISysResponse> FuncScheduleControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para)
	{
		//获取请求数据
		std::any& requestData = para->GetData();
		//执行业务逻辑
		if (requestData.type() == typeid(MdlCommonNS::ECommand))
		{
			//命令调度--转换命令
			MdlCommonNS::ECommand& cmd = std::any_cast<MdlCommonNS::ECommand&>(requestData);
			//执行调度
			m_pService->SwitchCmdService(cmd);
			//构造返回参数
			std::any data = std::make_any<bool>(true);
			auto pResult = new MdlCommonNS::DefSysResponse(data);
			return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
		}
		else
		{
			//功能调度
			return m_pService->SwitchFuncService(MdlCommonNS::EModuleType::E_Logger_Type,para);
		}
	}
}