#pragma once
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"

namespace LoggerNS
{
	class LModuleControl:public MdlCommonNS::IMdlOperat
	{
	public:
		LModuleControl();
		~LModuleControl();
	public:
		//构造模块
		virtual MdlCommonNS::ISysResponse* ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
		//销毁模块
		virtual MdlCommonNS::ISysResponse* DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para = nullptr) override;
		//获取模块状态
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//模块是否可用
	};
}


