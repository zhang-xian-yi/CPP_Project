#pragma once

namespace SerializationToolNS
{
	//游戏引擎的模块控制器
	class SerializationToolMdlControl
	{
	public:
		SerializationToolMdlControl();
		~SerializationToolMdlControl();
	public:
		//构造模块
		virtual bool ConstructModule();
		//销毁模块
		virtual bool DestoryModule();
		//获取模块状态
		virtual bool IsUse()const;
	private:
		bool m_bIsUse;//模块是否可用
	};
}


