#pragma once
// �������й���ģ�����ʵ�ֵ�ģ��������ֹͣ�ӿ�
#include <memory>
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
		virtual std::unique_ptr<ISysResponse> ConstructModule(const std::unique_ptr<ISysRequest> para = nullptr) = 0;
		//����ģ��
		virtual std::unique_ptr<ISysResponse> DestoryModule(const std::unique_ptr<ISysRequest> para = nullptr) = 0;
		//��ȡģ��״̬
		virtual bool IsUse() const = 0;
	};

}