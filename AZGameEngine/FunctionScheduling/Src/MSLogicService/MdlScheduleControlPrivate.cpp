#include "MdlScheduleControlPrivate.h"
#include "CMNInterface/IMdlOperat.h"
#include "CMNInterface/IMdlFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNServices/ServiceContainerSingle.h"//ҵ������
#include "CMNMEnum/ModuelType/EModuleType.h"//ģ������
#include "LoggerFactory.h"//��־������
#include "MdlScheduleFactory.h"//ģ����ȹ�����
#include "OpenGLUIFactory.h"//OPenglUI�Ĺ�����
#include "GameEngineFactory.h"//��Ϸ���湤����
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
		pFactory = MdlScheduleNS::MdlScheduleFactory::GetFactory();
		InitAndRegisterService(EModuleType::E_FuncSchedule_Type, pFactory);
		//��ʼ��/ע����־ʵ��
		pFactory = Log4CppNS::LoggerFactory::GetFactory();
		InitAndRegisterService(EModuleType::E_Logger_Type, pFactory);
		//��ʼ��/ע����Ϸ����ʵ��
		pFactory = AZGameEngineNS::GameEngineFactory::GetFactory();
		InitAndRegisterService(EModuleType::E_GameEngine_Type, pFactory);
		//��ʼ��/ע��OpenglUIʵ��
		pFactory = OpenGLUINS::OpenGLUIFactory::GetFactory();
		InitAndRegisterService(EModuleType::E_OpengGLUI_Type, pFactory);

		
	}

	/// <summary>
	/// ��ָ�����͵Ĺ���ָ�봴����ģ����ƶ����ҵ���߼����ƶ���ע������������
	/// </summary>
	/// <param name="type">ģ������</param>
	/// <param name="factory">��Ӧģ��Ŀ�������ָ��</param>
	void MdlScheduleControlPrivate::InitAndRegisterService(EModuleType type,IMdlFactory* factory)
	{
		//ע��˴���������new ���� ��Ҫ�������ָ����й���
		MdlCommonNS::IMdlOperat* pMdl = factory->CreateModuleInstance();
		MdlCommonNS::IMdlService* pService = factory->CreateServiceInstance();
		//��ʼ��ģ��
		pMdl->ConstructModule();
		//ע��ģ��
		ServiceContainerSingle::GetContainer().RegisterModuleInterface(type, pMdl, pService);
	}
}

