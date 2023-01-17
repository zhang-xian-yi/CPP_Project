#pragma once

#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace MdlScheduleNS
{
	/// <summary>
	/// 执行模块业务调度的服务
	/// </summary>
	class MdlOperatControl:public MdlCommonNS::IMdlOperat
	{
	public:
		MdlOperatControl();
		~MdlOperatControl();
	public:
		//构造模块
		virtual std::unique_ptr<MdlCommonNS::ISysResponse> ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
		//销毁模块
		virtual std::unique_ptr<MdlCommonNS::ISysResponse> DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
		//获取模块状态
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//模块是否可用
	};
}


