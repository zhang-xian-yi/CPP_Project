#pragma once
#include <MSCommon/MSExpMarcoDefine.h>
namespace CommonNS
{
	//前置声明 模块的启停和业务逻辑
	class IMdlOperat;
	class IMdlService;
	//前置声明，模块类型
	enum class EModuleType :unsigned char;
}

namespace MdlScheduleNS
{
	//业务逻辑实现类
	class ServiceContainerSinglePrivate;

	//保存项目生命周期中的全局服务实例
	class MdlScheduleDLLAPI ServiceContainerSingle
	{
	public:
		static ServiceContainerSingle& GetContainer()
		{
			static ServiceContainerSingle instance;
			return instance;
		}
	public:
		ServiceContainerSingle();
		~ServiceContainerSingle();
		//注册模块操作接口
		void RegisterModuleInterface(CommonNS::EModuleType mdlType, CommonNS::IMdlOperat* imdlOperat, CommonNS::IMdlService* imdlService);
		//注销模块操作接口
		void UnRegisterModuleInterface(CommonNS::EModuleType mdlType);
		//摧毁容器
		void DestoryContaineer();
		//获取模块操作接口
		CommonNS::IMdlOperat* GetModuleOperatInterface(CommonNS::EModuleType mdlType);
		CommonNS::IMdlService* GetModuleServiceInterface(CommonNS::EModuleType mdlType);
	private:
		ServiceContainerSinglePrivate* m_pService;
	};
}


