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
		void SetData(Any& data);
		//��ȡָ�����ݣ��ӽӿڴ��̳�
		virtual Any& GetData()const override;
	private:
		Any* m_pData;
	};
}

