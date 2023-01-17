#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������
/*
Լ�����������ģ���ҵ����Ⱦ���ҵ���߼�����������ִ��
*/


namespace MdlCommonNS
{
	//ǰ������ ģ�����ͣ��ҵ���߼�
	class IMdlOperat;
	class IMdlService;
	//ǰ��������ģ������
	enum class EModuleType :unsigned char;
}

namespace MdlCommonNS
{
	//ҵ���߼�ʵ����
	class ServiceContainerSinglePrivate;

	//������Ŀ���������е�ȫ�ַ���ʵ��
	class MdlCommonDLLAPI ServiceContainerSingle
	{
	public:
		static ServiceContainerSingle& GetContainer()
		{
			static ServiceContainerSingle instance;
			return instance;
		}
	public:
		//ע��ģ������ӿ�
		void RegisterModuleInterface(MdlCommonNS::EModuleType mdlType, MdlCommonNS::IMdlOperat* imdlOperat, MdlCommonNS::IMdlService* imdlService);
		//ע��ģ������ӿ�
		void UnRegisterModuleInterface(MdlCommonNS::EModuleType mdlType);
		//�ݻ�����
		void DestoryContaineer();
		//��ȡģ������ӿ�
		MdlCommonNS::IMdlOperat* GetModuleOperatInterface(MdlCommonNS::EModuleType mdlType);
		MdlCommonNS::IMdlService* GetModuleServiceInterface(MdlCommonNS::EModuleType mdlType);
	private:
		//��ֹ�������嵥������ֹdelelte ��������
		ServiceContainerSingle();
		~ServiceContainerSingle();
		ServiceContainerSingle(ServiceContainerSingle& instance) = delete;
		ServiceContainerSingle& operator=(const ServiceContainerSingle& instance) = delete;
	private:
		ServiceContainerSinglePrivate* m_pService;
	};
}


