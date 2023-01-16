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
		virtual ISysResponse* ConstructModule(const ISysRequest* para) = 0;
		//ע�ᵽģ����ȳ�����,��Ҫ��ȡģ����ȵķ����������ã�������ʵ���˽ӿڵ�ʵ����ע�ᵽ������
		virtual ISysResponse* RegisterModule(const ISysRequest* para) = 0;
		//����ģ��
		virtual ISysResponse* DestoryModule(const ISysRequest* para) = 0;
		//ע��ģ����ȳ����еĹ���ģ��,��Ҫ��ȡģ����ȵķ����������ã�������ʵ���˽ӿڵ�ʵ����ӷ����������Ƴ�
		virtual ISysResponse* UnRegisterModule(const ISysRequest* para) = 0;
		//��ȡģ��״̬
		virtual bool IsUse() const = 0;
	};

}