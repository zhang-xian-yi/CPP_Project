/********************************************************************************************
�ļ���			    :	ServiceContainerSingle.cpp
�ļ�·��			:   G:\ProjectSrcDIr\Vs2019ProjectSrcDIr\CPP_Project\AZGameEngine\MdlCommon\Src\CMNServices\Container
�ļ�����			:	������������Ҫʹ�õķ���ʵ���洢/��ȡ������
�޸ļ�¼			:
---------------------------------------------------------------------------------------------
Author			Version			Date		
������			1.0				2023/01/30    
********************************************************************************************/
#include "ServiceContainerSingle.h"
#include <map>
#include <unordered_map>
#include <memory>
#include "semaphore.h"//�ź���
#include "CMNMEnum/ModuelType/EModuleType.h"
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/IMdlService.h"


namespace MdlCommonNS
{
	//���������ĵ���ҵ���߼�����ʵ��
	//������������ʹ��ģ�����Ҳ��ɵ���ʱ������װ��ģʽ����4251����
	class ServiceContainerSinglePrivate
	{
	public:
		ServiceContainerSinglePrivate();
		~ServiceContainerSinglePrivate();
		//ע��ģ������ӿ�
		void RegisterModuleInterface(EModuleType mdlType, IMdlOperat* imdlOperat, IMdlService* imdlService);
		//ע��ģ������ӿ�
		void UnRegisterModuleInterface(EModuleType mdlType);
		//�ݻ�����
		void DestoryContaineer();
		//��ȡģ������ӿ�
		std::optional<MdlCommonNS::IMdlOperat*> GetModuleOperatInterface(EModuleType mdlType);
		std::optional<MdlCommonNS::IMdlService*> GetModuleServiceInterface(EModuleType mdlType);
	private:
		std::unordered_map<EModuleType, IMdlOperat*>* m_pMdlOperatMap;
		std::unordered_map<EModuleType, IMdlService*>* m_pMdlServiceMap;
	};

	/// <summary>
	/// ���캯��
	/// </summary>
	ServiceContainerSinglePrivate::ServiceContainerSinglePrivate()
		:m_pMdlOperatMap(new std::unordered_map<EModuleType, IMdlOperat*>()),
		 m_pMdlServiceMap(new std::unordered_map<EModuleType, IMdlService*>())
	{
	}
	//��������
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
		//����ȫ����Ϊ�ղ��������в�������
		if (m_pMdlOperatMap != nullptr && m_pMdlServiceMap != nullptr)
		{
			//��ӽ���map 
			m_pMdlOperatMap->insert(std::make_pair(mdlType, imdlOperat));
			m_pMdlServiceMap->insert(std::make_pair(mdlType, imdlService));
		}
	}

	/// <summary>
	/// ȡ��ע�� ͬʱ��Ϊ����ָ��Ĺ�ϵ��Ҳ���Զ��ͷŶ�Ӧ�ڴ�
	/// �����ٴ�ע�����Ҫ���´���ģ�������
	/// </summary>
	/// <param name="mdlType"></param>
	void ServiceContainerSinglePrivate::UnRegisterModuleInterface(EModuleType mdlType)
	{
		auto findOperat = m_pMdlOperatMap->find(mdlType);
		//���ڸ�����ָ��
		if (findOperat != m_pMdlOperatMap->end())
		{
			m_pMdlOperatMap->erase(mdlType);//ɾ����¼
		}

		auto findService = m_pMdlServiceMap->find(mdlType);
		//���ڸ�����ָ��
		if (findService != m_pMdlServiceMap->end())
		{
			m_pMdlServiceMap->erase(mdlType);//ɾ����¼
		}
	}

	void ServiceContainerSinglePrivate::DestoryContaineer()
	{
		//ѭ��ֹͣģ�����в�ɾ��ģ����ָͣ��,�������
		for (auto& item : (*m_pMdlOperatMap))
		{
			//�˴��ݻ�ģ���ƺ��ǵڶ��δݻ�
			item.second->DestoryModule(nullptr);
			//����
			delete item.second;
		}
		for (auto& item : (*m_pMdlServiceMap))
		{
			//����
			delete item.second;
		}
		//�����б����������ָ�룬������ʱ���Զ�ɾ����Ӧ�ռ�
		m_pMdlOperatMap->clear();
		m_pMdlServiceMap->clear();
	}

	std::optional<MdlCommonNS::IMdlOperat*> ServiceContainerSinglePrivate::GetModuleOperatInterface(EModuleType mdlType)
	{
		auto findp = m_pMdlOperatMap->find(mdlType);
		//���ڸ�����ָ��
		if (findp != m_pMdlOperatMap->end())
		{
			return findp->second;//��������ָ�뱣���ʵ��ָ��
		}
		return std::nullopt;//���ؿ�
	}
	std::optional<MdlCommonNS::IMdlService*> ServiceContainerSinglePrivate::GetModuleServiceInterface(EModuleType mdlType)
	{
		auto findp = m_pMdlServiceMap->find(mdlType);
		//���ڸ�����ָ��
		if (findp != m_pMdlServiceMap->end())
		{
			return findp->second;//��������ָ�뱣���ʵ��ָ��
		}
		return std::nullopt;//���ؿ�
	}

}

namespace MdlCommonNS
{
	//����߳�ͬʱע��ҵ��ʱ���߳�ͬ���ź���
	static sem_t _RegisteSemSig;

	/// <summary>
	/// ���캯��
	/// </summary>
	ServiceContainerSingle::ServiceContainerSingle()
		:m_pService(new ServiceContainerSinglePrivate())
	{
		sem_init(&_RegisteSemSig,0,1);//��ʼֵ1 ��ʾ�������1һ���߳�ʹ��
	}
	//��������
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
		//�ź��� -1 ����˺����������̵߳ȴ�
		sem_wait(&_RegisteSemSig);
		//����ȫ����Ϊ�ղ��������в�������
		m_pService->RegisterModuleInterface(mdlType, imdlOperat, imdlService);
		//�ź���+1 ���ѵȴ����߳�
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