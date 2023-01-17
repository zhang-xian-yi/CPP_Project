#include "ServiceContainerSingle.h"
#include <map>
#include <memory>
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
		IMdlOperat* GetModuleOperatInterface(EModuleType mdlType);
		IMdlService* GetModuleServiceInterface(EModuleType mdlType);
	private:
		std::map<EModuleType, std::unique_ptr<IMdlOperat>>* m_pMdlOperatMap;
		std::map<EModuleType, std::unique_ptr<IMdlService>>* m_pMdlServiceMap;
	};

	/// <summary>
	/// ���캯��
	/// </summary>
	ServiceContainerSinglePrivate::ServiceContainerSinglePrivate()
		:m_pMdlOperatMap(new std::map<EModuleType, std::unique_ptr<IMdlOperat>>()),
		 m_pMdlServiceMap(new std::map<EModuleType, std::unique_ptr<IMdlService>>())
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
			//����ָ����й���
			std::unique_ptr<IMdlOperat> pMdlControl(imdlOperat);
			std::unique_ptr<IMdlService> pServiceControl(imdlService);

			//��ӽ���map  ��ʱ�����ָͨ�룬�ȴ�֮����
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
			item.second->DestoryModule(nullptr);
		}
		//�����б����������ָ�룬������ʱ���Զ�ɾ����Ӧ�ռ�
		m_pMdlOperatMap->clear();
		m_pMdlServiceMap->clear();
	}

	IMdlOperat* ServiceContainerSinglePrivate::GetModuleOperatInterface(EModuleType mdlType)
	{
		auto findp = m_pMdlOperatMap->find(mdlType);
		//���ڸ�����ָ��
		if (findp != m_pMdlOperatMap->end())
		{
			return findp->second.get();//��������ָ�뱣���ʵ��ָ��
		}
		return nullptr;
	}
	IMdlService* ServiceContainerSinglePrivate::GetModuleServiceInterface(EModuleType mdlType)
	{
		auto findp = m_pMdlServiceMap->find(mdlType);
		//���ڸ�����ָ��
		if (findp != m_pMdlServiceMap->end())
		{
			return findp->second.get();//��������ָ�뱣���ʵ��ָ��
		}
		return nullptr;
	}

}

namespace MdlCommonNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	ServiceContainerSingle::ServiceContainerSingle()
		:m_pService(new ServiceContainerSinglePrivate())
	{
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
		//����ȫ����Ϊ�ղ��������в�������
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