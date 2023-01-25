#pragma once
//
#include "FSLogicService/IService.h"

namespace MdlCommonNS
{
	//ǰ������
	enum class EModuleType :unsigned char;
	class IMdlFactory;
}

namespace FuncScheduleNS
{
	/// <summary>
	/// ��ʼ���Լ�ע�����й���ģ���ҵ���߼�
	/// </summary>
	class InitAndRegisterAllService:public ICmdService
	{
	public:
		InitAndRegisterAllService() = default;
		virtual ~InitAndRegisterAllService() = default;
	public:
		//ִ��ҵ���߼���ں���
		virtual void DoService();
	private:
		//���ݹ������󴴽���ע��ָ��ʵ��
		void InitAndRegisterMdlAsync(MdlCommonNS::EModuleType type, MdlCommonNS::IMdlFactory* factory);
		bool InitAndRegisterMdl(MdlCommonNS::EModuleType type, MdlCommonNS::IMdlFactory* factory);
	};
}


