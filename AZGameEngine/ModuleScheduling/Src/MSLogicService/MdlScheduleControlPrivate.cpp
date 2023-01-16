#include "MdlScheduleControlPrivate.h"
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/IMdlFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNServices/ServiceContainerSingle.h"//ҵ������
#include "CMNMEnum/ModuelType/EModuleType.h"//ģ������
#include "LoggerFactory.h"//��־������
#include "MdlScheduleFactory.h"//ģ����ȹ�����
using namespace MdlCommonNS;

namespace MdlScheduleNS
{
	/// <summary>
	/// ��ʼ��/ע�� ���еĹ���ģ��
	/// </summary>
	void MdlScheduleControlPrivate::InitAndRegisterAllService()
	{
		IMdlFactory* pFactory = nullptr;
		//��ʼ��/ע��ģ�����ʵ��
		pFactory = &(MdlScheduleNS::MdlScheduleFactory::GetFactory());
		InitAndRegisterService(EModuleType::E_MdlSchedule_Type, pFactory);

		//��ʼ��/ע����־ʵ��
		pFactory = &(Log4CppNS::LoggerFactory::GetFactory());
		InitAndRegisterService(EModuleType::E_Logger_Type, pFactory);


		
	}

	/// <summary>
	/// ��ָ�����͵Ĺ���ָ�봴����ģ����ƶ����ҵ���߼����ƶ���ע������������
	/// </summary>
	/// <param name="type">ģ������</param>
	/// <param name="factory">��Ӧģ��Ŀ�������ָ��</param>
	void MdlScheduleControlPrivate::InitAndRegisterService(EModuleType type,IMdlFactory* factory)
	{
		MdlCommonNS::IMdlOperat* pMdl = factory->GetModuleInstance();
		MdlCommonNS::IMdlService* pService = factory->GetServiceInstance();
		//��ʼ��ģ��
		pMdl->ConstructModule();
		//ע��ģ��
		ServiceContainerSingle::GetContainer().RegisterModuleInterface(type, pMdl, pService);
	}
}

