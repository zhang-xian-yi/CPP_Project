#pragma once
#include "CMNInterface/IMdlOperat.h"
namespace OpenGLUINS
{
	class OpenGLUIMdlControl :public MdlCommonNS::IMdlOperat
	{
	public:
		OpenGLUIMdlControl();
		~OpenGLUIMdlControl();
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

