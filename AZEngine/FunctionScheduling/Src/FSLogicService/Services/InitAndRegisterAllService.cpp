#include "InitAndRegisterAllService.h"
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
#include "ImguiRenderer/Src/ImguiRendererFactory.h"//Imgui Renderer ������
namespace FuncScheduleNS
{
	using namespace MdlCommonNS;

	//��̬����
	static void LogInitMsg(EModuleType mdlType, std::future<bool>& result)
	{
		std::string mdlDesc = MdlCommonNS::EnumModuleTypeExtend::GetInstance().GetMdlCnDesc(mdlType);
		try
		{
			std::future_status m_status;
			do
			{
				//��ѯ�ȴ��첽ִ��
				m_status = result.wait_for(std::chrono::milliseconds(100));
				switch (m_status)
				{
				case std::future_status::ready:
					break;
				case std::future_status::timeout:
					
					break;
				case std::future_status::deferred:
					result.wait();
					break;
				default:
					break;
				}
			} while (m_status != std::future_status::ready);


			if (result.get())
			{
				std::string userMsg = mdlDesc + "ע��ɹ�";
				MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV, userMsg);
			}
			else
			{
				std::string userMsg = mdlDesc + "ע��ʧ��";
				MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV, userMsg);
			}
		}
		catch (std::exception& exp)
		{
			std::string userMsg = mdlDesc + "ע���쳣";
			std::string expMsg = exp.what();
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, userMsg);
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Error_LV, expMsg);
		}
	}


	void InitAndRegisterAllService::DoService()
	{
		/*ע��--ģ��Խ�������Ӵ��Ӧ��Խ��ע�ᣬ���ʱ��Լƽ��*/

		IMdlFactory* pFactory = nullptr;
		//��ʼ��/ע�ᴰ��ʵ��
		pFactory = WindowsNS::OpenGLWindowsFactory::GetFactory();
		std::future<bool> OWResult = InitAndRegisterMdlAsync(EModuleType::E_OpenGLWindow_Type, pFactory);
		//��ʼ��/ע����־ʵ��
		pFactory = LoggerNS::LoggerFactory::GetFactory();
		std::future<bool> logResult = InitAndRegisterMdlAsync(EModuleType::E_Logger_Type, pFactory);
		//ͬ�� ��ʼ��/ע��ϵͳ�¼�����ʵ��
		pFactory = EventDrivenSysNS::EventDrivenSysFactory::GetFactory();
		std::future<bool> EDSResult = InitAndRegisterMdlAsync(EModuleType::E_EventDrivenSys_Type, pFactory);
		//��ʼ��/ע�����ݼ���ʵ��
		pFactory = AZDataComputeNS::DataComputeFactory::GetFactory();
		std::future<bool> DCResult = InitAndRegisterMdlAsync(EModuleType::E_DataCompute_Type, pFactory);
		//��ʼ�� imguiRenderLayer
		pFactory = ImguiRendererNS::ImguiRendererFactory::GetFactory();
		std::future<bool> IRResult = InitAndRegisterMdlAsync(EModuleType::E_ImguiRenderer_Type, pFactory);



		//��ӡ��־ ImguiRendererNS
		LogInitMsg(EModuleType::E_Logger_Type, logResult);
		LogInitMsg(EModuleType::E_EventDrivenSys_Type, EDSResult);
		LogInitMsg(EModuleType::E_DataCompute_Type, DCResult);
		LogInitMsg(EModuleType::E_OpenGLWindow_Type, OWResult);
		LogInitMsg(EModuleType::E_ImguiRenderer_Type, IRResult);
	}
	/// <summary>
	/// �첽ִ������
	/// </summary>
	/// <param name="type"></param>
	/// <param name="factory"></param>
	std::future<bool> InitAndRegisterAllService::InitAndRegisterMdlAsync(MdlCommonNS::EModuleType type, MdlCommonNS::IMdlFactory* factory)
	{
		return std::async(&InitAndRegisterAllService::InitAndRegisterMdl, this, type, factory); // (2) async call 
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
			ServiceContainerSingle::GetInstance().RegisterModuleInterface(type, pMdl, pService);
			return rep;
		}
		catch (std::exception&)
		{
			//������־�Ƿ��ӡ������Ҫ����false
			return false;//��ʼ���쳣
		}
	}
}