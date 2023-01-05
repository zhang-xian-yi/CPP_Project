#pragma once
#include "Interface/IMdlOperat.h"
#include "Interface/ISysRequest.h"
#include "Interface/ISysResponse.h"

namespace Log4CppNS
{
	class LModuleControl:public CommonNS::IMdlOperat
	{
	public:
		LModuleControl();
		~LModuleControl();
	public:
		//构造模块
		virtual CommonNS::ISysResponse* ConstructModule(const CommonNS::ISysRequest& para) override;
		//注册到模块调度程序中,需要获取模块调度的服务容器引用，将自身实现了接口的实现类注册到容器中
		virtual CommonNS::ISysResponse* RegisterModule(const CommonNS::ISysRequest& para) override;
		//销毁模块
		virtual CommonNS::ISysResponse* DestoryModule(const CommonNS::ISysRequest& para) override;
		//注销模块调度程序中的功能模块,需要获取模块调度的服务容器引用，将自身实现了接口的实现类从服务容器中移除
		virtual CommonNS::ISysResponse* UnRegisterModule(const CommonNS::ISysRequest& para) override;
		//获取模块状态
		virtual bool IsUse()const override;
	private:
		bool m_bIsUse;//模块是否可用
	};
}


