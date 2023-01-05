#pragma once
// 定义所有功能模块必须实现的模块启动和停止接口
#include <Common/ExportMarcoDefine.h> //导出宏
#include <Interface/ISysRequest.h>
#include <Interface/ISysResponse.h>

namespace CommonNS
{
	//日志模块的模块
	class IMdlOperat
	{
	public:
		//构造模块
		virtual ISysResponse* ConstructModule(const ISysRequest& para) = 0;
		//注册到模块调度程序中,需要获取模块调度的服务容器引用，将自身实现了接口的实现类注册到容器中
		virtual ISysResponse* RegisterModule(const ISysRequest& para) = 0;
		//销毁模块
		virtual ISysResponse* DestoryModule(const ISysRequest& para) = 0;
		//注销模块调度程序中的功能模块,需要获取模块调度的服务容器引用，将自身实现了接口的实现类从服务容器中移除
		virtual ISysResponse* UnRegisterModule(const ISysRequest& para) = 0;
		//获取模块状态
		virtual bool IsUse() const = 0;
	};

}