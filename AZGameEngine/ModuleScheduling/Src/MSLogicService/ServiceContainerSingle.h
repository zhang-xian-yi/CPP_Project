#pragma once
#include <MSCommon/MSExpMarcoDefine.h>
namespace MdlCommonNS
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
		void RegisterModuleInterface(MdlCommonNS::EModuleType mdlType, MdlCommonNS::IMdlOperat* imdlOperat, MdlCommonNS::IMdlService* imdlService);
		//ע��ģ������ӿ�
		void UnRegisterModuleInterface(MdlCommonNS::EModuleType mdlType);
		//�ݻ�����
		void DestoryContaineer();
		//��ȡģ������ӿ�
		MdlCommonNS::IMdlOperat* GetModuleOperatInterface(MdlCommonNS::EModuleType mdlType);
		MdlCommonNS::IMdlService* GetModuleServiceInterface(MdlCommonNS::EModuleType mdlType);
	private:
		ServiceContainerSinglePrivate* m_pService;
	};
}


