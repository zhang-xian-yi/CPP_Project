#pragma once
#include <map>
#include <memory>
#include "IService.h"//ICmdService,IFuncService ����
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
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
		MdlCommonNS::ISysResponse* SwitchCmdService(MdlCommonNS::ECommand cmd);
		//ѡ��ҵ��ķ�֧
		MdlCommonNS::ISysResponse* SwitchFuncService(MdlCommonNS::EModuleType mdlTpye,const std::unique_ptr<MdlCommonNS::ISysRequest>& para);
	private:
		void InitData();
	private:
		//����ϵͳ�����ʵ��ҵ���߼���ӳ���
		std::map<MdlCommonNS::ECommand, std::unique_ptr<ICmdService>>* m_pCmdServiceMap;
	};
}


