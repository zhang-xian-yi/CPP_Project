#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <CMNInterface/ISysRequest.h>
#include <any>
namespace MdlCommonNS
{
	class MdlCommonDLLAPI DefSysRequest:public ISysRequest
	{
	public:
		DefSysRequest();
		~DefSysRequest();
	public:
		//����ָ�����ݣ����Ҹ���ֱ�ӿ���any������ڴ�
		void SetData(std::any& data);
		//��ȡָ�����ݣ��ӽӿڴ��̳�
		virtual std::any& GetData()const override;
	private:
		std::any* m_pData;
	};
}


