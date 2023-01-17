#include "ServiceContainerSingle.h"
#include <map>
#include <memory>
#include "CMNMEnum/ModuelType/EModuleType.h"
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/IMdlService.h"


namespace MdlCommonNS
{
	//服务容器的单例业务逻辑具体实现
	//但凡导出类中使用模板类且不可导出时，采用装饰模式避免4251警告
	class ServiceContainerSinglePrivate
	{
	public:
		ServiceContainerSinglePrivate();
		~ServiceContainerSinglePrivate();
		//注册模块操作接口
		void RegisterModuleInterface(EModuleType mdlType, IMdlOperat* imdlOperat, IMdlService* imdlService);
		//注销模块操作接口
		void UnRegisterModuleInterface(EModuleType mdlType);
		//摧毁容器
		void DestoryContaineer();
		//获取模块操作接口
		IMdlOperat* GetModuleOperatInterface(EModuleType mdlType);
		IMdlService* GetModuleServiceInterface(EModuleType mdlType);
	private:
		std::map<EModuleType, std::unique_ptr<IMdlOperat>>* m_pMdlOperatMap;
		std::map<EModuleType, std::unique_ptr<IMdlService>>* m_pMdlServiceMap;
	};

	/// <summary>
	/// 构造函数
	/// </summary>
	ServiceContainerSinglePrivate::ServiceContainerSinglePrivate()
		:m_pMdlOperatMap(new std::map<EModuleType, std::unique_ptr<IMdlOperat>>()),
		 m_pMdlServiceMap(new std::map<EModuleType, std::unique_ptr<IMdlService>>())
	{
	}
	//析构函数
	ServiceContainerSinglePrivate::~ServiceContainerSinglePrivate()
	{
		if (m_pMdlOperatMap != nullptr)
		{

			delete m_pMdlOperatMap;
			m_pMdlOperatMap = nullptr;
		}
		if (m_pMdlOperatMap != nullptr)
		{

			delete m_pMdlServiceMap;
			m_pMdlServiceMap = nullptr;
		}
	}
	void ServiceContainerSinglePrivate::RegisterModuleInterface(EModuleType mdlType, IMdlOperat* imdlOperat, IMdlService* imdlService)
	{
		//必须全部不为空才能向其中插入数据
		if (m_pMdlOperatMap != nullptr && m_pMdlServiceMap != nullptr)
		{
			//智能指针进行管理
			std::unique_ptr<IMdlOperat> pMdlControl(imdlOperat);
			std::unique_ptr<IMdlService> pServiceControl(imdlService);

			//添加进入map  暂时添加普通指针，等待之后尝试
			m_pMdlOperatMap->insert(std::make_pair(mdlType, imdlOperat));
			m_pMdlServiceMap->insert(std::make_pair(mdlType, imdlService));
		}
	}

	/// <summary>
	/// 取消注册 同时因为智能指针的关系，也会自动释放对应内存
	/// 所以再次注册便需要重新创建模块控制器
	/// </summary>
	/// <param name="mdlType"></param>
	void ServiceContainerSinglePrivate::UnRegisterModuleInterface(EModuleType mdlType)
	{
		auto findOperat = m_pMdlOperatMap->find(mdlType);
		//存在该类型指针
		if (findOperat != m_pMdlOperatMap->end())
		{
			m_pMdlOperatMap->erase(mdlType);//删除记录
		}

		auto findService = m_pMdlServiceMap->find(mdlType);
		//存在该类型指针
		if (findService != m_pMdlServiceMap->end())
		{
			m_pMdlServiceMap->erase(mdlType);//删除记录
		}
	}

	void ServiceContainerSinglePrivate::DestoryContaineer()
	{
		//循环停止模块运行并删除模块启停指针,清空容器
		for (auto& item : (*m_pMdlOperatMap))
		{
			item.second->DestoryModule(nullptr);
		}
		//容器中保存的是智能指针，被清理时会自动删除对应空间
		m_pMdlOperatMap->clear();
		m_pMdlServiceMap->clear();
	}

	IMdlOperat* ServiceContainerSinglePrivate::GetModuleOperatInterface(EModuleType mdlType)
	{
		auto findp = m_pMdlOperatMap->find(mdlType);
		//存在该类型指针
		if (findp != m_pMdlOperatMap->end())
		{
			return findp->second.get();//返回智能指针保存的实际指针
		}
		return nullptr;
	}
	IMdlService* ServiceContainerSinglePrivate::GetModuleServiceInterface(EModuleType mdlType)
	{
		auto findp = m_pMdlServiceMap->find(mdlType);
		//存在该类型指针
		if (findp != m_pMdlServiceMap->end())
		{
			return findp->second.get();//返回智能指针保存的实际指针
		}
		return nullptr;
	}

}

namespace MdlCommonNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	ServiceContainerSingle::ServiceContainerSingle()
		:m_pService(new ServiceContainerSinglePrivate())
	{
	}
	//析构函数
	ServiceContainerSingle::~ServiceContainerSingle()
	{
		if (m_pService != nullptr)
		{
			delete m_pService;
			m_pService = nullptr;
		}
	}
	void ServiceContainerSingle::RegisterModuleInterface(EModuleType mdlType, IMdlOperat* imdlOperat, IMdlService* imdlService)
	{
		//必须全部不为空才能向其中插入数据
		m_pService->RegisterModuleInterface(mdlType, imdlOperat, imdlService);
	}
	void ServiceContainerSingle::UnRegisterModuleInterface(EModuleType mdlType)
	{
		m_pService->UnRegisterModuleInterface(mdlType);
	}

	void ServiceContainerSingle::DestoryContaineer()
	{
		m_pService->DestoryContaineer();
	}

	IMdlOperat* ServiceContainerSingle::GetModuleOperatInterface(EModuleType mdlType)
	{
		return m_pService->GetModuleOperatInterface(mdlType);
	}
	IMdlService* ServiceContainerSingle::GetModuleServiceInterface(EModuleType mdlType)
	{
		return m_pService->GetModuleServiceInterface(mdlType);
	}
}