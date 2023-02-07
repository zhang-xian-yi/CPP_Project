#include "InitAndRegisterAllService.h"
#include <future>//�첽ִ��ͷ�ļ�
#include <thread>
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"//ģ����Ҫ�ӿ�
#include "MdlCommon/Src/CMNInterface/IMdlFactory.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"//ģ������
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "Logger/Src/ILogger.h"
#include "Logger/Src/LoggerFactory.h"//��־������
#include "FunctionScheduling/Src/FuncScheduleFactory.h"//ģ����ȹ�����
#include "OpenGLWindowUI/Src/OpenGLWindowsFactory.h"//OPenglUI�Ĺ�����
#include "AZDataCompute/Src/DataComputeFactory.h"//���ݼ���������
#include "EventDrivenSystem/Src/EventDrivenSysFactory.h"//
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
		pFactory = EventDrivenSysNS::EventDrivenSysFactory::GetFactory();
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
			std::string msg = MdlCommonNS::EnumModuleTypeExtend::GetInstance().GetMdlCnDesc(type) + "ע��ɹ�";
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV, msg);
			return rep;
		}
		catch (std::exception exp)
		{
			std::string userMsg = MdlCommonNS::EnumModuleTypeExtend::GetInstance().GetMdlCnDesc(type) + "ע��ʧ��";
			std::string expMsg  =  exp.what();
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, userMsg);
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, expMsg);
			//������־�Ƿ��ӡ������Ҫ����false
			return false;//��ʼ���쳣
		}
	}
}