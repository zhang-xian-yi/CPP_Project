#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <CMNInterface/ISysRequest.h>
namespace MdlCommonNS
{
	/*
	Լ��  Any��������ڶ��������ڴ棬������֮�����ý��������ڴ��ƽ��������
	*/
	class Any;

	class MdlCommonDLLAPI DefSysRequest:public ISysRequest
	{
	public:
		DefSysRequest();
		~DefSysRequest();
	public:
		//����ָ�����ݣ����Ҹ���ֱ�ӿ���any������ڴ�
		void SetData(Any& data);
		//��ȡָ�����ݣ��ӽӿڴ��̳�
		virtual Any& GetData()const override;
	private:
		Any* m_pData;
	};
}


