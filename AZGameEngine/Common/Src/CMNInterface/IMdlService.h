#pragma once

//�������й���ģ���ҵ���߼�ִ�����
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <CMNInterface/ISysRequest.h>
#include <CMNInterface/ISysResponse.h>
namespace CommonNS
{
	//ģ��ҵ���߼��ӿ�
	class CommonDLLAPI IMdlService
	{
	public:
		virtual ~IMdlService() = 0;
	public:
		//ִ��ҵ���߼���ں���,�������Ϊ��
		virtual ISysResponse* DoService(const ISysRequest* para) = 0;
	};
}