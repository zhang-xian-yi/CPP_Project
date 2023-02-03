#pragma once
// 定义所有功能模块必须实现的模块启动和停止接口
#include <any>
#include "MdlCommon/Src/CMNMacro/CMNExpMarcoDefine.h" //导出宏


namespace MdlCommonNS
{
	//日志模块的模块
	class MdlCommonDLLAPI IMdlOperat
	{
	public:
		virtual ~IMdlOperat() = 0;
	public:
		//构造模块
		virtual bool ConstructModule() = 0;
		//销毁模块
		virtual bool DestoryModule() = 0;
		//获取模块状态
		virtual bool IsUse() const = 0;
	};

}