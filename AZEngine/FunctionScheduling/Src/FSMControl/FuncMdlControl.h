#pragma once

#include "CMNInterface/IMdlOperat.h"
namespace FuncScheduleNS
{
	/// <summary>
	/// 执行模块业务调度的服务
	/// </summary>
	class FuncMdlControl:public MdlCommonNS::IMdlOperat
	{
	public:
		FuncMdlControl();
		~FuncMdlControl();
	public:
		//构造模块
		virtual bool ConstructModule() override;
		//销毁模块
		virtual bool DestoryModule() override;
		//获取模块状态
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//模块是否可用
	};
}


