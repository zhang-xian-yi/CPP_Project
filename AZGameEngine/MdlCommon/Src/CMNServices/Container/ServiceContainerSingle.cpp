/********************************************************************************************
文件名			    :	ServiceContainerSingle.cpp
文件路径			:   G:\ProjectSrcDIr\Vs2019ProjectSrcDIr\CPP_Project\AZGameEngine\MdlCommon\Src\CMNServices\Container
文件描述			:	引擎中所有需要使用的服务实例存储/获取的容器
修改记录			:
---------------------------------------------------------------------------------------------
Author			Version			Date		
张贤忆			1.0				2023/01/30    
********************************************************************************************/
#include "ServiceContainerSingle.h"
#include <map>
#include <unordered_map>
#include <memory>
#include "semaphore.h"//信号量
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
		std::optional<MdlCommonNS::IMdlOperat*> GetModuleOperatInterface(EModuleType mdlType);
		std::optional<MdlCommonNS::IMdlService*> GetModuleServiceInterface(EModuleType mdlType);
	private:
		std::unordered_map<EModuleType, IMdlOperat*>* m_pMdlOperatMap;
		std::unordered_map<EModuleType, IMdlService*>* m_pMdlServiceMap;
	};

	/// <summary>
	/// 构造函数
	/// </summary>
	ServiceContainerSinglePrivate::ServiceContainerSinglePrivate()
		:m_pMdlOperatMap(new std::unordered_map<EModuleType, IMdlOperat*>()),
		 m_pMdlServiceMap(new std::unordered_map<EModuleType, IMdlService*>())
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
			//添加进入map 
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
			//此处摧毁模块似乎是第二次摧毁
			item.second->DestoryModule(nullptr);
			//销毁
			delete item.second;
		}
		for (auto& item : (*m_pMdlServiceMap))
		{
			//销毁
			delete item.second;
		}
		//容器中保存的是智能指针，被清理时会自动删除对应空间
		m_pMdlOperatMap->clear();
		m_pMdlServiceMap->clear();
	}

	std::optional<MdlCommonNS::IMdlOperat*> ServiceContainerSinglePrivate::GetModuleOperatInterface(EModuleType mdlType)
	{
		auto findp = m_pMdlOperatMap->find(mdlType);
		//存在该类型指针
		if (findp != m_pMdlOperatMap->end())
		{
			return findp->second;//返回智能指针保存的实际指针
		}
		return std::nullopt;//返回空
	}
	std::optional<MdlCommonNS::IMdlService*> ServiceContainerSinglePrivate::GetModuleServiceInterface(EModuleType mdlType)
	{
		auto findp = m_pMdlServiceMap->find(mdlType);
		//存在该类型指针
		if (findp != m_pMdlServiceMap->end())
		{
			return findp->second;//返回智能指针保存的实际指针
		}
		return std::nullopt;//返回空
	}

}

namespace MdlCommonNS
{
	//多个线程同时注册业务时的线程同步信号量
	static sem_t _RegisteSemSig;

	/// <summary>
	/// 构造函数
	/// </summary>
	ServiceContainerSingle::ServiceContainerSingle()
		:m_pService(new ServiceContainerSinglePrivate())
	{
		sem_init(&_RegisteSemSig,0,1);//初始值1 表示最多允许1一个线程使用
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
		//信号量 -1 进入此函数的其余线程等待
		sem_wait(&_RegisteSemSig);
		//必须全部不为空才能向其中插入数据
		m_pService->RegisterModuleInterface(mdlType, imdlOperat, imdlService);
		//信号量+1 唤醒等待的线程
		sem_post(&_RegisteSemSig);
	}
	void ServiceContainerSingle::UnRegisterModuleInterface(EModuleType mdlType)
	{
		m_pService->UnRegisterModuleInterface(mdlType);
	}

	void ServiceContainerSingle::DestoryContaineer()
	{
		m_pService->DestoryContaineer();
	}

	std::optional<MdlCommonNS::IMdlOperat*> ServiceContainerSingle::GetModuleOperatInterface(EModuleType mdlType)
	{
		return m_pService->GetModuleOperatInterface(mdlType);
	}
	std::optional<MdlCommonNS::IMdlService*> ServiceContainerSingle::GetModuleServiceInterface(EModuleType mdlType)
	{
		return m_pService->GetModuleServiceInterface(mdlType);
	}
}