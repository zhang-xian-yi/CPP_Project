#pragma once
// 定义所有功能模块必须实现的模块启动和停止接口
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
#include <CMNInterface/ISysRequest.h>
#include <CMNInterface/ISysResponse.h>

namespace MdlCommonNS
{
	//日志模块的模块
	class MdlCommonDLLAPI IMdlOperat
	{
	public:
		virtual ~IMdlOperat() = 0;
	public:
		//构造模块
		virtual ISysResponse* ConstructModule(const ISysRequest* para = nullptr) = 0;
		//销毁模块
		virtual ISysResponse* DestoryModule(const ISysRequest* para = nullptr) = 0;
		//获取模块状态
		virtual bool IsUse() const = 0;
	};

}