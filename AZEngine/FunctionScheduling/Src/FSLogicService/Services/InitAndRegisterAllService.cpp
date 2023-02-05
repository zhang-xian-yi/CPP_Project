#include "InitAndRegisterAllService.h"
#include <future>//�첽ִ��ͷ�ļ�
#include <thread>
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"//ģ����Ҫ�ӿ�
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"//ģ������
#include "Logger/Src/ILogger.h"
#include "Logger/Src/LoggerFactory.h"//��־������
#include "FunctionScheduling/Src/FuncScheduleFactory.h"//ģ����ȹ�����
#include "OpenGLWindowUI/Src/OpenGLWindowsFactory.h"//OPenglUI�Ĺ�����
#include "AZDataCompute/Src/DataComputeFactory.h"//���ݼ���������
#include "SystemEventDriven/Src/SysEventDrivenFactory.h"//
namespace FuncScheduleNS
{
	using namespace MdlCommonNS;

	void InitAndRegisterAllService::DoService()
	{
		IMdlFactory* pFactory = nullptr;
		//��ʼ��/ע����־ʵ��
		pFactory = LoggerNS::LoggerFactory::GetFactory();
		InitAndRegisterMdl(EModuleType::E_Logger_Type, pFactory);
		//��ʼ��/ע�ᴰ��ʵ��
		pFactory = WindowsNS::OpenGLWindowsFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_OpenGLWindow_Type, pFactory);
		//��ʼ��/ע�����ݼ���ʵ��
		pFactory = AZDataComputeNS::DataComputeFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_DataCompute_Type, pFactory);
		//��ʼ��/ע��ϵͳ�¼�����ʵ��
		pFactory = SysEventDNS::SysEventDrivenFactory::GetFactory();
		InitAndRegisterMdlAsync(EModuleType::E_SysEventDriven_Type, pFactory);
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
				prunlog->LogFileMsgAsync(LoggerNS::ELogLevel::E_Info_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance().GetMdlCnDesc(type)+"ע��ɹ�");
				auto pstdoutlog = iLogS.value()->ConvertType<LoggerNS::IStdoutLogger*>();
				pstdoutlog->LogStdoutMsgAsync(LoggerNS::ELogLevel::E_Info_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance().GetMdlCnDesc(type) + "ע��ɹ�");
			}
			return rep;
		}
		catch (std::exception exp)
		{
			auto iLogS = ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_Logger_Type);
			if (iLogS.has_value())
			{
				auto prunlog = iLogS.value()->ConvertType<LoggerNS::IFileLogger*>();
				prunlog->LogFileMsgAsync(LoggerNS::ELogLevel::E_Error_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance().GetMdlCnDesc(type) + "ע��ʧ��");
				prunlog->LogFileMsgAsync(LoggerNS::ELogLevel::E_Error_LV, exp.what());
				auto pstdoutlog = iLogS.value()->ConvertType<LoggerNS::IStdoutLogger*>();
				pstdoutlog->LogStdoutMsgAsync(LoggerNS::ELogLevel::E_Error_LV, MdlCommonNS::EnumModuleTypeExtend::GetInstance().GetMdlCnDesc(type) + "ע��ʧ��");
				pstdoutlog->LogStdoutMsgAsync(LoggerNS::ELogLevel::E_Error_LV, exp.what());
			}
			//������־�Ƿ��ӡ������Ҫ����false
			return false;//��ʼ���쳣
		}
	}
}