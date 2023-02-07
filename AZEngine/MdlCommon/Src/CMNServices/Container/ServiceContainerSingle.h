#pragma once
#include <memory>
#include <optional>
#include "MdlCommon/Src/CMNMacro/CMNExpMarcoDefine.h" //导出宏
#include "MdlCommon/Src/CMNMacro/CoreMacroDef.h"
/*
约定，所有针对模块的业务调度均由业务逻辑的容器单例执行
约定：
1 此下的头文件引入必须放在此头文件中， 各个模块的实际调度
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
		SingletonSelfConstruct(ServiceContainerSingle)
	public:
		//注册模块操作接口
		void RegisterModuleInterface(MdlCommonNS::EModuleType mdlType, MdlCommonNS::IMdlOperat* imdlOperat, MdlCommonNS::IMdlService* imdlService);
		//注销模块操作接口
		void UnRegisterModuleInterface(MdlCommonNS::EModuleType mdlType);
		//摧毁容器
		void DestoryContaineer();
		//获取模块操作接口
		std::optional<MdlCommonNS::IMdlOperat*> GetModuleOperatInterface(MdlCommonNS::EModuleType mdlType);
		std::optional<MdlCommonNS::IMdlService*> GetModuleServiceInterface(MdlCommonNS::EModuleType mdlType);

	private:
		ServiceContainerSinglePrivate* m_pService;
	};
}


