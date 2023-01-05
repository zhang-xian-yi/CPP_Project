#pragma once
// �������й���ģ�����ʵ�ֵ�ģ��������ֹͣ�ӿ�
#include <Common/ExportMarcoDefine.h> //������
#include <Interface/ISysRequest.h>
#include <Interface/ISysResponse.h>

namespace CommonNS
{
	//��־ģ���ģ��
	class IMdlOperat
	{
	public:
		//����ģ��
		virtual ISysResponse* ConstructModule(const ISysRequest& para) = 0;
		//ע�ᵽģ����ȳ�����,��Ҫ��ȡģ����ȵķ����������ã�������ʵ���˽ӿڵ�ʵ����ע�ᵽ������
		virtual ISysResponse* RegisterModule(const ISysRequest& para) = 0;
		//����ģ��
		virtual ISysResponse* DestoryModule(const ISysRequest& para) = 0;
		//ע��ģ����ȳ����еĹ���ģ��,��Ҫ��ȡģ����ȵķ����������ã�������ʵ���˽ӿڵ�ʵ����ӷ����������Ƴ�
		virtual ISysResponse* UnRegisterModule(const ISysRequest& para) = 0;
		//��ȡģ��״̬
		virtual bool IsUse() const = 0;
	};

}