#pragma once

//�������й���ģ���ҵ���߼�ִ�����
#include <Common/ExportMarcoDefine.h> //������
#include <Interface/ISysRequest.h>
#include <Interface/ISysResponse.h>
namespace CommonNS
{
	//ģ��ҵ���߼��ӿ�
	class IMdlService
	{
	public:
		//ִ��ҵ���߼���ں���
		virtual ISysResponse* DoService(const ISysRequest& para) = 0;
	};
}