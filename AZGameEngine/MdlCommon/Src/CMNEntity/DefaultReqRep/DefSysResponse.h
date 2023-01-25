#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <CMNInterface/ISysResponse.h>

namespace MdlCommonNS
{
	//�ӿ�ʵ����
	class MdlCommonDLLAPI DefSysResponse :public ISysResponse
	{
	public:
		DefSysResponse();
		~DefSysResponse();
	public:
		//����ָ�����ݣ����Ҹ���ֱ�ӿ���any������ڴ�
		void SetData(std::any& data);
		//��ȡָ�����ݣ��ӽӿڴ��̳�
		virtual std::any& GetData()const override;
	private:
		std::any* m_pData;
	};
}

