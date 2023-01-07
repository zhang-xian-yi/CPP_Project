#pragma once
#include <MSCommon/MSExpMarcoDefine.h>
namespace CommonNS
{
	//ǰ������ ģ�����ͣ��ҵ���߼�
	class IMdlOperat;
	class IMdlService;
	//ǰ��������ģ������
	enum class EModuleType :unsigned char;
}

namespace MdlScheduleNS
{
	//ҵ���߼�ʵ����
	class ServiceContainerSinglePrivate;

	//������Ŀ���������е�ȫ�ַ���ʵ��
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
		//ע��ģ������ӿ�
		void RegisterModuleInterface(CommonNS::EModuleType mdlType, CommonNS::IMdlOperat* imdlOperat, CommonNS::IMdlService* imdlService);
		//ע��ģ������ӿ�
		void UnRegisterModuleInterface(CommonNS::EModuleType mdlType);
		//�ݻ�����
		void DestoryContaineer();
		//��ȡģ������ӿ�
		CommonNS::IMdlOperat* GetModuleOperatInterface(CommonNS::EModuleType mdlType);
		CommonNS::IMdlService* GetModuleServiceInterface(CommonNS::EModuleType mdlType);
	private:
		ServiceContainerSinglePrivate* m_pService;
	};
}


