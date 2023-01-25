#pragma once

//�������й���ģ���ҵ���߼�ִ�����
#include <memory>
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
		//ִ��ҵ���߼���ں���,�������Ϊ��,����ָ��ʵ������ָ�룬�����ڿ������ƵĿ���
		virtual std::unique_ptr<ISysResponse> DoService(const std::unique_ptr<ISysRequest>& para = nullptr) = 0;
	};
}