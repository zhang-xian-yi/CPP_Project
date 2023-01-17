#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
/*
约定，所有针对模块的业务调度均由业务逻辑的容器单例执行
*/


namespace MdlCommonNS
{
	//前置声明 模块的启停和业务逻辑
	class IMdlOperat;
	class IMdlService;
	//前置声明，模块类型
	enum class EModuleType :unsigned char;
}

namespace MdlCommonNS
{
	//业务逻辑实现类
	class ServiceContainerSinglePrivate;

	//保存项目生命周期中的全局服务实例
	class MdlCommonDLLAPI ServiceContainerSingle
	{
	public:
		static ServiceContainerSingle& GetContainer()
		{
			static ServiceContainerSingle instance;
			return instance;
		}
	public:
		//注册模块操作接口
		void RegisterModuleInterface(MdlCommonNS::EModuleType mdlType, MdlCommonNS::IMdlOperat* imdlOperat, MdlCommonNS::IMdlService* imdlService);
		//注销模块操作接口
		void UnRegisterModuleInterface(MdlCommonNS::EModuleType mdlType);
		//摧毁容器
		void DestoryContaineer();
		//获取模块操作接口
		MdlCommonNS::IMdlOperat* GetModuleOperatInterface(MdlCommonNS::EModuleType mdlType);
		MdlCommonNS::IMdlService* GetModuleServiceInterface(MdlCommonNS::EModuleType mdlType);
	private:
		//禁止反复定义单例，禁止delelte 单例对象
		ServiceContainerSingle();
		~ServiceContainerSingle();
		ServiceContainerSingle(ServiceContainerSingle& instance) = delete;
		ServiceContainerSingle& operator=(const ServiceContainerSingle& instance) = delete;
	private:
		ServiceContainerSinglePrivate* m_pService;
	};
}


