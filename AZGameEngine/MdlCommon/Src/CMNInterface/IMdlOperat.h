#pragma once
// �������й���ģ�����ʵ�ֵ�ģ��������ֹͣ�ӿ�
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <CMNInterface/ISysRequest.h>
#include <CMNInterface/ISysResponse.h>

namespace MdlCommonNS
{
	//��־ģ���ģ��
	class MdlCommonDLLAPI IMdlOperat
	{
	public:
		virtual ~IMdlOperat() = 0;
	public:
		//����ģ��
		virtual ISysResponse* ConstructModule(const ISysRequest* para = nullptr) = 0;
		//����ģ��
		virtual ISysResponse* DestoryModule(const ISysRequest* para = nullptr) = 0;
		//��ȡģ��״̬
		virtual bool IsUse() const = 0;
	};

}