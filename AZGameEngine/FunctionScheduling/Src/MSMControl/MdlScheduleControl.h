#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"
namespace MdlScheduleNS
{
	//ǰ������
	class MdlScheduleControlPrivate;

	/// <summary>
	/// ����ģ����ȵ��߼�
	/// </summary>
	class MdlScheduleControl:public MdlCommonNS::IMdlService
	{
	public:
		MdlScheduleControl();
		~MdlScheduleControl();
	public:
		MdlCommonNS::ISysResponse* DoService(const MdlCommonNS::ISysRequest* para);
	private:

	private:
		MdlScheduleControlPrivate* m_pService;//����ʵ�ֵ�ҵ����ָ��
	};
}


