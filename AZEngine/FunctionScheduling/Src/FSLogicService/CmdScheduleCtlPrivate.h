#pragma once
#include <any>
#include <unordered_map>
#include <memory>
#include "IService.h"//ICmdService,IFuncService ����
/*
ע�� ����ģ��ĵ���ͨ��ȫ�������洢��ģʽ����
     ϵͳ����ͨ������-��ɢ��ģʽ���д���
*/

namespace MdlCommonNS
{
	//ǰ������
	enum class ECommand :unsigned char;
	enum class EModuleType :unsigned char;
}
namespace FuncScheduleNS
{
	/// <summary>
	/// ģ����ȵĿ�����ʵ��˽���߼�
	/// </summary>
	class CmdScheduleCtlPrivate
	{
	public:
		CmdScheduleCtlPrivate();
		~CmdScheduleCtlPrivate();
		//ѡ��ҵ��ķ�֧
		std::any SwitchCmdService(MdlCommonNS::ECommand cmd);

	private:
		void InitData();
	private:
		//����ϵͳ�����ʵ��ҵ���߼���ӳ���
		std::unordered_map<MdlCommonNS::ECommand, ICmdService*>* m_pCmdServiceMap;
	};
}


