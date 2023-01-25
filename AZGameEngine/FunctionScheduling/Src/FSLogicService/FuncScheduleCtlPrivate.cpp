#include "FuncScheduleCtlPrivate.h"
#include <memory> //unique_ptr
#include <string>//�ַ���
#include <tuple>//Ԫ��
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"//Ĭ���������Ӧ
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNServices/ServiceContainerSingle.h"//ҵ������
using namespace MdlCommonNS;

namespace FuncScheduleNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	FuncScheduleCtlPrivate::FuncScheduleCtlPrivate()
		:m_pCmdServiceMap(new std::map<MdlCommonNS::ECommand, std::unique_ptr<ICmdService>>()),
		 m_pFuncServiceMap(new std::map<MdlCommonNS::EModuleType, std::unique_ptr<IFuncService>>())
	{

	}
	/// <summary>
	/// ��������
	/// </summary>
	FuncScheduleCtlPrivate::~FuncScheduleCtlPrivate()
	{
		if (m_pCmdServiceMap)
		{
			m_pCmdServiceMap->clear();
			delete m_pCmdServiceMap;
		}
		if (m_pFuncServiceMap)
		{
			m_pFuncServiceMap->clear();
			delete m_pFuncServiceMap;
		}
	}
	/// <summary>
	/// ����ҵ���߼�
	/// </summary>
	/// <param name="cmd"></param>
	/// <returns></returns>
	std::unique_ptr<MdlCommonNS::ISysResponse> FuncScheduleCtlPrivate::SwitchCmdService(MdlCommonNS::ECommand cmd)
	{
		auto find = m_pCmdServiceMap->find(cmd);
		//���췵�ز���
		std::any data ;
		if (find != m_pCmdServiceMap->end())
		{
			//ִ��ָ����ҵ���߼�
			find->second->DoService();
			//���췵�ز���
			data = std::tuple<bool, std::string>(true, "");
		}
		else
		{
			//���췵�ز��� û���ҵ���Ӧ���������
			data = std::tuple<bool,std::string>(false,"");
		}
		//���췵�ز���
		auto pResult = new MdlCommonNS::DefSysResponse(data);
		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}

	/// <summary>
	/// ���ܵ���ҵ���߼�
	/// </summary>
	/// <param name="mdlTpye"></param>
	/// <param name="para"></param>
	/// <returns></returns>
	std::unique_ptr<MdlCommonNS::ISysResponse> FuncScheduleCtlPrivate::SwitchFuncService(MdlCommonNS::EModuleType mdlTpye, const std::unique_ptr<MdlCommonNS::ISysRequest>& para)
	{
		auto find = m_pFuncServiceMap->find(mdlTpye);
		//���췵�ز���
		std::any data;
		if (find != m_pFuncServiceMap->end())
		{
			//ִ��ָ����ҵ���߼�
			find->second->DoService(para);
			//���췵�ز���
			data = std::tuple<bool, std::string>(true, "");
		}
		else
		{
			//���췵�ز���
			data = std::tuple<bool, std::string>(false, "");
		}
		//���췵�ز���
		auto pResult = new MdlCommonNS::DefSysResponse(data);
		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}

}

