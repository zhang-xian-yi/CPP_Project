#include "CmdScheduleCtlPrivate.h"
#include <memory> //unique_ptr
#include <string>//�ַ���
#include <tuple>//Ԫ��
#include "CMNServices/Container/ServiceContainerSingle.h"//ҵ������
#include "CMNInterface/IMdlService.h"
#include "CMNMEnum/Command/ECommand.h"
#include "CMNMEnum/ModuelType/EModuleType.h"
#include "Services/InitAndRegisterAllService.h"//��ʼ�����е�ҵ��
#include "Services/StopAndUnRegisterAllService.h"//ֹͣ���е�ҵ��
namespace FuncScheduleNS
{
	using namespace MdlCommonNS;
	/// <summary>
	/// ���캯��
	/// </summary>
	CmdScheduleCtlPrivate::CmdScheduleCtlPrivate()
		:m_pCmdServiceMap(new std::unordered_map<MdlCommonNS::ECommand, ICmdService*>())
	{
		InitData();
	}
	/// <summary>
	/// ��������
	/// </summary>
	CmdScheduleCtlPrivate::~CmdScheduleCtlPrivate()
	{
		if (m_pCmdServiceMap)
		{
			//�ṹ���� ����������map ע��C17��׼��֧�ֽṹ����
			for (auto&[cmd,inter] : *m_pCmdServiceMap)
			{
				delete inter;//ɾ��������ʵ��
			}
			m_pCmdServiceMap->clear();
			delete m_pCmdServiceMap;
		}
	}
	/// <summary>
	/// ����ҵ���߼�
	/// </summary>
	/// <param name="cmd"></param>
	/// <returns></returns>
	std::any CmdScheduleCtlPrivate::SwitchCmdService(MdlCommonNS::ECommand cmd)
	{
		auto find = m_pCmdServiceMap->find(cmd);
		if (find != m_pCmdServiceMap->end())
		{
			//ִ��ָ����ҵ���߼�
			find->second->DoService();
			//���췵�ز���
			return std::tuple<bool, std::string>(true, "");
		}
		else
		{
			//���췵�ز��� û���ҵ���Ӧ���������
			return std::tuple<bool,std::string>(false,"");
		}
	}

	/// <summary>
	/// ��ʼ������������
	/// </summary>
	void CmdScheduleCtlPrivate::InitData()
	{
		m_pCmdServiceMap->insert(std::make_pair(ECommand::E_InitAllFunction, new InitAndRegisterAllService()));
		m_pCmdServiceMap->insert(std::make_pair(ECommand::E_DestoryAllFunction, new StopAndUnRegisterAllService()));
	}

}

