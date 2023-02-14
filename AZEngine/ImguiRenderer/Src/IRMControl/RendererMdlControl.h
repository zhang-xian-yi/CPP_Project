#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"
namespace ImguiRendererNS
{
	class RendererMdlControl:MdlCommonNS::IMdlOperat
	{
	public:
		RendererMdlControl()=default;
		~RendererMdlControl() = default;
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

