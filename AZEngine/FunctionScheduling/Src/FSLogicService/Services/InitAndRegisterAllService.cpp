#include "InitAndRegisterAllService.h"
#include <future>//�첽ִ��ͷ�ļ�
#include <thread>
#include "CMNInterface/IMdlOperat.h"//ģ������ӿ�
#include "CMNInterface/IMdlFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "CMNMEnum/ModuelType/EModuleType.h"//ģ������
#include "LoggerFactory.h"//��־������
#include "FuncScheduleFactory.h"//ģ����ȹ�����
#include "OpenGLUIFactory.h"//OPenglUI�Ĺ�����
#include "GameEngineFactory.h"//��Ϸ���湤����
namespace FuncScheduleNS
{
	using namespace MdlCommonNS;

	void InitAndRegisterAllService::DoService()
	{
		IMdlFactory* pFactory = nullptr;
		//��ʼ��/ע��ģ�����ʵ��
		pFactory = FuncScheduleNS::FuncScheduleFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_FuncSchedule_Type, pFactory);
		//��ʼ��/ע����־ʵ��
		pFactory = LoggerNS::LoggerFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_Logger_Type, pFactory);
		//��ʼ��/ע����Ϸ����ʵ��
		pFactory = AZGameEngineNS::GameEngineFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_GameEngine_Type, pFactory);
		//��ʼ��/ע��OpenglUIʵ��
		pFactory = OpenGLUINS::OpenGLUIFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_OpengGLUI_Type, pFactory);

	}
	/// <summary>
	/// �첽ִ������
	/// </summary>
	/// <param name="type"></param>
	/// <param name="factory"></param>
	void InitAndRegisterAllService::InitAndRegisterMdlAsync(MdlCommonNS::EModuleType type, MdlCommonNS::IMdlFactory* factory)
	{
		auto result = std::async(&InitAndRegisterAllService::InitAndRegisterMdl, this, type, factory); // (2) async call 

		//TODO ��Ҫ��ȫ�ֱ������б�ǡ�type��ģ���Ѿ����г�ʼ��
		bool initFlag = result.get();

	}

	/// <summary>
	/// ��ʼ����ע�����ʵҵ���߼�
	/// </summary>
	/// <param name="type"></param>
	/// <param name="factory"></param>
	/// <returns></returns>
	bool InitAndRegisterAllService::InitAndRegisterMdl(MdlCommonNS::EModuleType type, MdlCommonNS::IMdlFactory* factory)
	{
		try
		{
			//ע��˴���������new ���� ��Ҫ�������ָ����й���
			MdlCommonNS::IMdlOperat* pMdl = factory->CreateModuleInstance();
			MdlCommonNS::IMdlService* pService = factory->CreateServiceInstance();
			//��ʼ��ģ��
			bool rep = pMdl->ConstructModule();
		
			//ע��ģ��
			ServiceContainerSingle::GetContainer().RegisterModuleInterface(type, pMdl, pService);
			return rep;
		}
		catch (std::exception exp)
		{
			auto iLogS = ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_Logger_Type);
			if (iLogS.has_value())
			{
				//�������

			}
			//������־�Ƿ��ӡ������Ҫ����false
			return false;//��ʼ���쳣
		}
	}
}