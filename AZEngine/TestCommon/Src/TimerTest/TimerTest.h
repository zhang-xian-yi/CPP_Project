#pragma once
//���ڴ���ִ��ʱ����Ե��࣬�����ඨ�嵽����ִ��ǰ��
//�ȵ�����ִ����ϣ���������ʱ�Զ���ӡִ��ʱ�䣬���ڲ���ʱʹ�ã��ұ�����ֲ��Commonģ��
#include <Macro/CMNExpMarcoDefine.h>
#include<chrono>//ʱ�����

namespace TestCommonNS
{
	//���ڴ���ĳ��������ľ���ִ��ʱ��
	class TestCommonDLLAPI TimerTest
	{
	public:
		TimerTest();
		~TimerTest();
	private:
		void stop();//ֹͣ
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimepoint;
	};
}

