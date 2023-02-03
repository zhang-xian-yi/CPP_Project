#include "InitAndRegisterAllService.h"
#include <future>//�첽ִ��ͷ�ļ�
#include <thread>
#include "CMNInterface/IMdlOperat.h"//ģ������ӿ�
#include "CMNInterface/IMdlFactory.h"
#include "CMNInterface/IMdlService.h"
#include "CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "CMNMEnum/ModuelType/EModuleType.h"//ģ������
#include "LoggerFactory.h"//��־������
#include "ILogger.h"
#include "FuncScheduleFactory.h"//ģ����ȹ�����
#include "OpenGLUIFactory.h"//OPenglUI�Ĺ�����
#include "GameEngineFactory.h"//��Ϸ���湤����
namespace FuncScheduleNS
{
	using namespace MdlCommonNS;

	void InitAndRegisterAllService::DoService()
	{
		IMdlFactory* pFactory = nullptr;
		//��ʼ��/ע����־ʵ��
		pFactory = LoggerNS::LoggerFactory::GetFactory();
		InitAndRegisterMdl(EModuleType::E_Logger_Type, pFactory);
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
			//������־��ӡ��ע����־ģ���������ע������ͬ��
			auto iLogS = ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_Logger_Type);
			if (iLogS.has_value())
			{
				auto prunlog = iLogS.value()->ConvertType<LoggerNS::IFileLogger*>();
				prunlog->LogFileMsgAsync(LoggerNS::ELogLevel::E_Info_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance()->GetMdlCnDesc(type)+"ע��ɹ�");
				auto pstdoutlog = iLogS.value()->ConvertType<LoggerNS::IStdoutLogger*>();
				pstdoutlog->LogStdoutMsgAsync(LoggerNS::ELogLevel::E_Info_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance()->GetMdlCnDesc(type) + "ע��ɹ�");
			}
			return rep;
		}
		catch (std::exception exp)
		{
			auto iLogS = ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_Logger_Type);
			if (iLogS.has_value())
			{
				auto prunlog = iLogS.value()->ConvertType<LoggerNS::IFileLogger*>();
				prunlog->LogFileMsgAsync(LoggerNS::ELogLevel::E_Error_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance()->GetMdlCnDesc(type) + "ע��ʧ��");
				prunlog->LogFileMsgAsync(LoggerNS::ELogLevel::E_Error_LV, exp.what());
				auto pstdoutlog = iLogS.value()->ConvertType<LoggerNS::IStdoutLogger*>();
				pstdoutlog->LogStdoutMsgAsync(LoggerNS::ELogLevel::E_Error_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance()->GetMdlCnDesc(type) + "ע��ʧ��");
				pstdoutlog->LogStdoutMsgAsync(LoggerNS::ELogLevel::E_Error_LV, exp.what());
			}
			//������־�Ƿ��ӡ������Ҫ����false
			return false;//��ʼ���쳣
		}
	}
}