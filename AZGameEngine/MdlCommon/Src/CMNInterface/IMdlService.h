#pragma once

//�������й���ģ���ҵ���߼�ִ�����
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <CMNInterface/ISysRequest.h>
#include <CMNInterface/ISysResponse.h>
namespace MdlCommonNS
{
	//ģ��ҵ���߼��ӿ�
	class MdlCommonDLLAPI IMdlService
	{
	public:
		virtual ~IMdlService() = 0;
	public:
		//ִ��ҵ���߼���ں���,�������Ϊ��
		virtual ISysResponse* DoService(const ISysRequest* para) = 0;
	};
}