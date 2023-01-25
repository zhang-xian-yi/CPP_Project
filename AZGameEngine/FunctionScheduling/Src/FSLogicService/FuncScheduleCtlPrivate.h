#pragma once
#include <map>
#include <memory>
#include "IService.h"//ICmdService,IFuncService ����
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
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
	class FuncScheduleCtlPrivate
	{
	public:
		FuncScheduleCtlPrivate();
		~FuncScheduleCtlPrivate();
		//ѡ��ҵ��ķ�֧
		std::unique_ptr<MdlCommonNS::ISysResponse> SwitchCmdService(MdlCommonNS::ECommand cmd);
		//ѡ��ҵ��ķ�֧
		std::unique_ptr<MdlCommonNS::ISysResponse> SwitchFuncService(MdlCommonNS::EModuleType mdlTpye,const std::unique_ptr<MdlCommonNS::ISysRequest>& para);
	private:
		//����ϵͳ�����ʵ��ҵ���߼���ӳ���
		std::map<MdlCommonNS::ECommand, std::unique_ptr<ICmdService>>* m_pCmdServiceMap;
		//�����û������ʵ��ҵ���߼���ӳ���
		std::map<MdlCommonNS::EModuleType, std::unique_ptr<IFuncService>>* m_pFuncServiceMap;
	};
}


